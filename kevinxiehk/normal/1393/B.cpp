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
    int n;
    int count[10];
    for(int i = 0; i < 9; i++) count[i] = 0;
    map<int, int> freq;
    int t;
    cin >> n;
    while(n--) {
        cin >> t;
        freq[t]++;
    }
    for(auto x: freq) {
        count[min(8LL, x.se)]++;
    }
    cin >> n;
    char c;
    while(n--) {
        cin >> c;
        cin >> t;
        if(c == '-') {
            count[min(8LL, freq[t])]--;
            freq[t]--;
            count[min(8LL, freq[t])]++;
            // cerr << freq[t] << '\n';
        }
        else {
            count[min(8LL, freq[t])]--;
            freq[t]++;
            count[min(8LL, freq[t])]++;
            // cerr << freq[t] << '\n';
        }
        bool can = false;
        if(count[8] > 0) can = true;
        if(count[4] + count[5] + count[6] + count[7] > 0) {
            int x = 0;
            for(int i = 2; i <= 8; i++) x += count[i] * (i / 2);
            if(x >= 4) can = true;
        }
        if(can) cout << "YES\n";
        else cout << "NO\n";
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