#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a);i<(b);i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
typedef pair<int,ll> pill;

pill pt[19][400005];
pill pj[19][400005];

int main() {
    int q; ll last = 0;
    int cnt = 1;

    fo(i,0,19) {
        pt[i][0] = pj[i][0] = pill(0, 1e16);
    }
    fo(i,0,19) {
        pt[i][1] = pj[i][1] = pill(0, i > 0 ? 1e16 : 0);
    }

    scanf("%d", &q);
    fo(_,0,q) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            ll p; ll  w;
            scanf("%lld %lld", &p, &w);
            p ^= last; w ^= last;
            cnt++;
            pt[0][cnt] = pill(p, w);
            fo(i,1,19) {
                pt[i][cnt].first = pt[i-1][pt[i-1][cnt].first].first;
                pt[i][cnt].second = max(pt[i-1][cnt].second, pt[i-1][pt[i-1][cnt].first].second);
            }
            int jp = p;
            for (int i = 18; i >= 0; i--) {
                if (pt[i][jp].second < w) jp = pt[i][jp].first;
            }
            pj[0][cnt] = pill(jp, w);
            fo(i,1,19) {
                pj[i][cnt].first = pj[i-1][pj[i-1][cnt].first].first;
                pj[i][cnt].second = pj[i-1][cnt].second + pj[i-1][pj[i-1][cnt].first].second;
            }
        } else {
            ll p; ll x;
            scanf("%lld %lld", &p, &x);
            p ^= last; x ^= last;
            int ln = 0;
            for (int i = 18; i >= 0; i--) {
                if (pj[i][p].second <= x) {
                    x -= pj[i][p].second;
                    p = pj[i][p].first;
                    ln += 1 << i;
                }
            }
            printf("%d\n", ln);
            last = ln;
        }
    }
}