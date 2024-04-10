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
bool not_prime[1000005];
void sieve() {
    for(int i = 2; i <= 1000000; i++) {
        if(not_prime[i] == false) {
            for(int j = i * i; j <= 1000000; j += i) {
                not_prime[j] = true;
            }
        }
    }
    return;
}
void solve(int TC) {
    int n, e;
    cin >> n >> e;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    vector<int> tmp;
    vector<bool> tmp2;
    for(int i = 0; i < e; i++) {
        tmp.clear();
        tmp2.clear();
        int tc = 1;
        for(int j = i; j < n; j += e) {
            if(arr[j] == 1) tc++;
            else {
                tmp.pb(tc);
                tmp2.pb(not_prime[arr[j]]);
                tc = 1;
            }
        }
        tmp.pb(tc);

        for(int j = 0; j < tmp.size() - 1; j++) {
            if(tmp2[j] == false) ans += tmp[j] * tmp[j + 1] - 1;
        }
    }
    cout << ans << '\n';
}
signed main(){
    sieve();
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}