#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct pt
{
    int x, y;
};

int dist(const pt& a, const pt& b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    map<int, vector<int> > init;

    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        init[c].pb(i);
    }

    vector<int> id(n, -2);
    map<int, vector<int> > v = init;
    bool ok = true;
    for (int i = 0; i < n; i += 2) {
        int len = dist(p[i], p[(i - 1 + n) % n]) + dist(p[i], p[i + 1]);
        if (v.count(len)) {
            id[i] = v[len].back();
            v[len].pop_back();
            if (v[len].empty()) {
                v.erase(len);
            }
        } else {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << id[i] + 1 << " ";
        }
        cout << "\n";
        return 0;
    }

    ok = true;
    v = init;
    id.assign(n, -2);

    for (int i = 1; i < n; i += 2) {
        int len = dist(p[i], p[i - 1]) + dist(p[i], p[(i + 1) % n]);
        if (v.count(len)) {
            id[i] = v[len].back();
            v[len].pop_back();
            if (v[len].empty()) {
                v.erase(len);
            }
        } else {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << id[i] + 1 << " ";
        }
        cout << "\n";
        return 0;
    }

    cout << "NO\n";

}