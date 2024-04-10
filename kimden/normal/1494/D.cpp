#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int a[502][502];
map<int, int> parent;
map<int, int> money;
const int INF = 1001001;

struct person {
    int who = -1;
    int leaf = -1;
    vector<int> q;

    bool operator < (const person& rhs) const {
        if (q.back() != rhs.q.back()) {
            return q.back() < rhs.q.back();
        }
        return who < rhs.who;
    }
    bool eq(const person& rhs) const {
        if (q.back() != rhs.q.back()) {
            return false;
        }
        if (a[leaf][rhs.leaf] != q.back()) {
            return false;
        }
        return true;
    }
};

set<person> people;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
        money[i] = a[i][i];
        person p;
        p.who = i;
        p.leaf = i;
        auto& v = p.q;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                v.push_back(a[i][j]);
            }
        }
        sort(all(v));
        v.push_back(INF);
        v.resize(unique(all(v)) - v.begin());
        reverse(all(v));
        people.insert(p);
    }
    int sz = n;
    int root = -1;
    while (1) {
        vector<person> pp;
        person p = *people.begin();
        people.erase(p);
        if (p.q.back() == INF) {
            root = p.who;
            break;
        }
        pp.push_back(p);
        while (!people.empty() && p.q.back() == people.begin()->q.back()) {
            pp.push_back(*people.begin());
            people.erase(people.begin());
        }
        vector<int> heads;
        vector<int> minleaf;
        for (int i = 0; i < pp.size(); ++i) {
            bool found = false;
            for (int j = 0; j < heads.size(); ++j) {
                if (pp[heads[j]].eq(pp[i])) {
                    found = true;
                    parent[pp[i].who] = sz + j;
                    minleaf[j] = min(minleaf[j], pp[i].leaf);
                    break;
                }
            }
            if (!found) {
                parent[pp[i].who] = sz + (int)heads.size();
                heads.push_back(i);
                minleaf.push_back(pp[i].leaf);
            }
        }
        for (int i = 0; i < heads.size(); ++i) {
            int j = heads[i];
            money[sz + i] = pp[j].q.back();
            pp[j].q.pop_back();
            pp[j].who = sz + i;
            pp[j].leaf = minleaf[i];
            people.insert(pp[j]);
        }
        sz += heads.size();
    }
    cout << sz << "\n";
    for (int i = 0; i < sz; ++i) {
        cout << money[i] << " ";
    }
    cout << "\n";
    cout << root + 1 << "\n";
    for (const pii& p: parent) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }



}