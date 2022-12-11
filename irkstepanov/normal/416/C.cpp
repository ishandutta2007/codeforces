#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct group
{
    int size, cost, id;
    bool operator<(const group& other) const
    {
        if (cost != other.cost) {
            return cost > other.cost;
        }
        if (size != other.size) {
            return size < other.size;
        }
        if (id != other.id) {
            return id < other.id;
        }
        return false;
    }
};

struct table
{
    int size, id;
    bool operator<(const table& other) const
    {
        if (size != other.size) {
            return size < other.size;
        }
        if (id != other.id) {
            return id < other.id;
        }
        return false;
    }
};

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");

    int n;
    cin >> n;
    vector<group> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i].size >> g[i].cost;
        g[i].id = i;
    }
    sort(all(g));

    int k;
    cin >> k;
    vector<table> t(k);
    vector<char> used(k, false);
    for (int i = 0; i < k; ++i) {
        cin >> t[i].size;
        t[i].id = i;
    }
    sort(all(t));

    int money = 0;
    vector<pii> ans;
    for (int i = 0; i < n; ++i) {
        int j = 0;
        for (; j < k && (used[j] || t[j].size < g[i].size); ++j) ;
        if (j == k) {
            continue;
        }
        money += g[i].cost;
        ans.pb(mp(g[i].id, t[j].id));
        used[j] = true;
    }

    cout << sz(ans) << " " << money << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

}