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
void solve(int TC) {
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int pta = 0, ptb = 0;
    int ls = -1;
    string c = "";
    int lef = k;
    while(pta < n && ptb < m) {
        if(lef == 0) {
            if(ls == 1) {
                c += b[ptb];
                ptb++;
                ls = 2;
            }
            else {
                c += a[pta];
                pta++;
                ls = 1;
            }
            lef = k - 1;
        }
        else {
            if(a[pta] < b[ptb]) {
                c += a[pta];
                pta++;
                if(ls == 1) lef--;
                else lef = k - 1;
                ls = 1;
            }
            else {
                c += b[ptb];
                ptb++;
                if(ls == 2) lef--;
                else lef = k - 1;
                ls = 2;
            }
        }
    }
    cout << c << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}