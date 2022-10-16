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
    map<int, int> freq;
    vector<int> can;
    int n, k;
    cin >> n >> k;
    int t;
    while(n--) {
        cin >> t;
        freq[t]++;
        if(freq[t] == k) can.pb(t);
    }
    sort(can.begin(), can.end());
    if(can.size() == 0) {
        cout << "-1\n";
        return;
    }
    int l = can[0], len = 1, r = can[0];
    int tl = can[0], mlen = 1;
    for(int i = 1; i < can.size(); i++) {
        if(can[i] == can[i - 1] + 1) {
            len++;
            r = can[i];
            if(len > mlen) {
                tl = l;
                mlen = len;
            }
        }
        else {
            l = r = can[i];
            len = 1;
        }
    }
    cout << tl << ' ' << tl + mlen - 1 << '\n';
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