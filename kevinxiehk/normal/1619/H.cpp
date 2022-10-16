#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
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
void gay(int TC) {cout << "Case #" << TC << ": ";}
void solve(int TC) {
    int n, q;
    cin >> n >> q;
    int sqrtn = sqrt(n);
    pair<int, int> nx[n + 5];
    int ls[n + 5];
    for(int i = 1; i <= n; i++) {cin >> nx[i].fi; ls[nx[i].fi] = i;}
    for(int i = 1; i <= n; i++) {
        int now = i;
        for(int _ = 0; _ < sqrtn; _++) now = nx[now].fi;
        nx[i].se = now;
    }
    int t, a, b;
    while(q--) {
        cin >> t >> a >> b;
        if(t == 2) {
            while(b >= sqrtn) {
                b -= sqrtn;
                a = nx[a].se;
            }
            while(b > 0) {
                b--;
                a = nx[a].fi;
            }
            cout << a << '\n';
        }
        else {
            swap(nx[a].fi, nx[b].fi);
            swap(ls[nx[a].fi], ls[nx[b].fi]);
            vector<int> hm;
            int now = a;
            for(int i = 0; i < sqrtn; i++) {
                now = nx[now].fi;
                hm.pb(now);
            }
            now = a;
            for(int i = sqrtn - 1; i >= 0; i--) {
                nx[now].se = hm[i];
                now = ls[now];
            }

            hm.clear();
            now = b;
            for(int i = 0; i < sqrtn; i++) {
                now = nx[now].fi;
                hm.pb(now);
            }
            now = b;
            for(int i = sqrtn - 1; i >= 0; i--) {
                nx[now].se = hm[i];
                now = ls[now];
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}