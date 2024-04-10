#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 1e5+5;
const int M = 1e5+5;

const int CITY = 0;
const int TOWER = 1;

int n, m;
// { x, type }
// type : 0/1 = city/tower
vector<pair<ll,int>> pts;
ll l[N+M], r[N+M];

int main () {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        ll a;
        scanf("%lld", &a);
        pts.pb({ a, CITY });
    }
    for (int i = 0; i < m; i++) {
        ll a;
        scanf("%lld", &a);
        pts.pb({ a, TOWER });
    }

    pts.pb({ LLONG_MIN/2LL, TOWER });
    pts.pb({ LLONG_MAX/2LL, TOWER });

    sort(pts.begin(), pts.end());

    for (int i = 1; i < (int)pts.size(); i++) {
        l[i] = l[i-1];
        if (pts[i].second == TOWER)
            l[i] = i;
    }

    r[(int)pts.size()-1] = (int)pts.size()-1;
    for (int i = (int)pts.size()-2; i >= 0; i--) {
        r[i] = r[i+1];
        if (pts[i].second == TOWER)
            r[i] = i;
    }

    ll maxdist = 0;
    for (int i = 0; i < (int)pts.size(); i++) {
        if (pts[i].second == CITY) {
            ll dist_to_tower = min(
                    pts[i].first - pts[l[i]].first,
                    pts[r[i]].first - pts[i].first);
            logg(i, pts[i].first, dist_to_tower);
            maxdist = max(maxdist, dist_to_tower); 
        }
    }

    printf("%lld\n", maxdist);

    return 0;
}