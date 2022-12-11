#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<int, pii> mapa;
    set<int> cost[4];

    int n;
    cin >> n;
    vector<int> p(n), a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        mapa[p[i]] = {a[i], b[i]};
        cost[a[i]].insert(p[i]);
        cost[b[i]].insert(p[i]);
    }

    int q;
    cin >> q;

    while (q--) {
        int c;
        cin >> c;
        if (cost[c].empty()) {
            cout << "-1 ";
            continue;
        }
        int x = *cost[c].begin();
        cout << x << " ";
        cost[c].erase(cost[c].begin());
        pii p = mapa[x];
        if (p.first != c) {
            cost[p.first].erase(x);
        }
        if (p.second != c) {
            cost[p.second].erase(x);
        }
    }
    cout << "\n";

}