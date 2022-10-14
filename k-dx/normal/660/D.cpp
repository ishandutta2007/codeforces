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

const int N = 2005;

int n;
pair<ll,ll> pts[N];

ll slabnia (ll a) {
    return (a+1LL)*a/2LL;
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &pts[i].first, &pts[i].second);
    }

    vector<vector<ll>> segs; //haha

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto p1 = pts[i];
            auto p2 = pts[j];

            if (p1.first > p2.first) swap(p1, p2);
            if (p1.first == p2.first and p1.second > p2.second) swap(p1, p2);

            segs.pb({ p2.first - p1.first, p2.second - p1.second });
        }
    }

    sort(segs.begin(), segs.end());

    // for (int i = 0; i < (int)segs.size(); i++) {
    //     auto e = segs[i];
    //     deb("%lld, %lld %lld\n", e[0], e[1], e[2]);
    // }

    ll ans = 0;
    ll akt = 0;
    for (int i = 0; i < (int)segs.size(); i++) {
        if (i != 0 and segs[i-1] != segs[i]) {
            if (akt >= 2) ans += slabnia(akt-1);
            akt = 0;
        }
        akt++;
    }
    if (akt >= 2) ans += slabnia(akt);

    printf("%lld\n", ans/2);

    return 0;
}