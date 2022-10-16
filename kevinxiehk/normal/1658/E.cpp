#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;    
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
struct rect{
    pair<int, int> l, r;
};
rect intersect(rect a, rect b) {
    rect x;
    x.l.fi = max(a.l.fi, b.l.fi);
    x.l.se = max(a.l.se, b.l.se);

    x.r.fi = min(a.r.fi, b.r.fi);
    x.r.se = min(a.r.se, b.r.se);
    return x;
}
bool ins(rect a, pair<int, int> x) {
    return (x.fi >= a.l.fi && x.se <= a.r.se && x.se >= a.l.se && x.fi <= a.r.fi);
}
int can[4000005];
pair<int, int> pl[4000005];
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int arr[n + 5][n + 5];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)  {
            cin >> arr[i][j];
            pl[arr[i][j]] = mp(i + j - 2, j - i + n - 1);
        }
    }
    rect in;
    in.l = mp(-inf, -inf);
    in.r = mp(inf, inf);
    for(int i = n * n; i >= 1; i--) {
        if(ins(in, pl[i])) {
            can[i] = 1;
            rect t;
            t.l = mp(pl[i].fi - k, pl[i].se - k);
            t.r = mp(pl[i].fi + k, pl[i].se + k);
            in = intersect(in, t);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cout << "GM"[can[arr[i][j]]];
        cout << '\n';
    }
    return 0;
}