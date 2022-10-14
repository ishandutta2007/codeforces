#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int n;
int p[MAXN], pos[MAXN], bio[MAXN];
vector <pi> v;
vector <vector <int> > r;

void f (int a, int b) {
    v.push_back({a, b});
    pos[p[a]] = b; pos[p[b]] = a;
    swap(p[a], p[b]);
}

void get_cik () {
    r.clear();
    for (int i = 1; i <= n; i++) bio[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (bio[i]) continue;
        vector <int> tmp;
        int curr = i;
        while (1) {
            tmp.push_back(curr);
            bio[curr] = 1;
            curr = p[curr];
            if (curr == i) break;
        }
        r.push_back(tmp);
    }
}

void solve_one (vector <int> a) {
    f(pos[a[0]], pos[a[1]]);
    f(pos[a[0]], pos[a.back()]);
    for (int i = 1; i < (int) a.size() - 1; i++) {
        f(pos[a[i]], pos[p[a[i]]]);
    }
    f(pos[a[0]], pos[a.back()]);
}

void solve_pair (vector <int> a, vector <int> b) {
    f(pos[a[0]], pos[b[0]]);
    for (int i = 0; i < (int) a.size() - 1; i++) {
        f(pos[a[i]], pos[p[a[i]]]);
    }
    for (int i = 0; i < (int) b.size() - 1; i++) {
        f(pos[b[i]], pos[p[b[i]]]);
    }
    f(pos[a.back()], pos[b.back()]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    get_cik();
    if (r.size() == 1) {
        solve_one(r[0]);
    } else {
        while (r.size() >= 2) {
            solve_pair(r[r.size() - 2], r[r.size() - 1]);
            r.pop_back(); r.pop_back();
        }
        if (!r.empty()) {
            int ind = -1;
            for (int i = 1; i <= n; i++) {
                if (p[i] == i) ind = i;
            }
            solve_pair(r[0], {ind});
        }
    }
    cout << v.size() << '\n';
    for (auto pp : v) cout << pp.first << " " << pp.second << '\n';
    return 0;
}