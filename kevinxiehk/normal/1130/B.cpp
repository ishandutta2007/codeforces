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
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> aa[n + 5];
    int t;
    aa[0].pb(0); aa[0].pb(0);
    for(int i = 0; i < n * 2; i++) {
        int t;
        cin >> t;
        aa[t].pb(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += abs(aa[i][0] - aa[i - 1][0]);
        ans += abs(aa[i][1] - aa[i - 1][1]);
    }
    cout << ans << '\n';
    return 0;
}