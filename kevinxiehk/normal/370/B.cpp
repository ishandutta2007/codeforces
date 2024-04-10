#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
int n;
bool hv[105][105];
vector<int> conn[1000005];
bool vi[1000005];

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
bool nt[105];
void solve() {  
    cin >> n;
    int t, tt;
    for(int i = 0; i < n; i++) {
        cin >> t;
        while(t--) {
            cin >> tt;
            hv[i][tt] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int all = true;
            for(int k = 1; k <= 100; k++) {
                if(hv[i][k]) {
                    all &= hv[j][k];
                }
            }
            if(all) nt[j] = true;
        }
    }
    for(int i = 0; i < n; i++) cout << ((nt[i] == true) ? "NO\n" : "YES\n");
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    //cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    while(t--) solve();
    return 0;
}