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
void gay(int TC) {cout << "Case #" << TC << ": ";}
int dsu[35][100005];
bool eve[35][100005];
int f(int id, int x) {
    if(x == dsu[id][x]) return x;
    return dsu[id][x] = f(id, dsu[id][x]);
}
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 32; j++) dsu[j][i] = i;
    }
    int a, b, w;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        for(int j = 0; j < 30; j++) {
            if((w >> j) & 1) {
                if(eve[j][f(j, a)]) eve[j][f(j, b)] = true;
                dsu[j][f(j, a)] = f(j, b);
            }
        }
        if(w % 2 == 0) {
            // dsu[30][f(30, a)] = f(30, b);
            for(int j = 0; j < 30; j++) {
                eve[j][f(j, a)] = eve[j][f(j, b)] = true;
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        cin >> a >> b;
        int can = false;
        int can2 = false;
        for(int i = 0; i < 30; i++) {
            if(f(i, a) == f(i, b)) can = true;
            if(i != 0 && eve[i][f(i, a)]) can2 = true;
        }
        if(can) cout << "0\n";
        else if(can2) cout << "1\n";
        else cout << "2\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}