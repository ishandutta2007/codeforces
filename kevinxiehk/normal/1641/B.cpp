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
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    for(auto x: freq) if(x.se % 2 == 1) {
        cout << "-1\n";
        return;
    }
    int addinfront = 0;
    vector<pair<int, int>> ops;
    vector<int> ans;
    for(int i = 0; i < n; i += 2) {
        int a = i + 1;
        while(arr[a] != arr[i]) a++;
        for(int j = i + 1; j < a; j++) {
            ops.pb(mp(addinfront + a - i + j - i, arr[j]));
        }
        ans.pb((a - i) * 2);
        addinfront += (a - i) * 2;
        for(int j = i + 1; j * 2 <= i + a; j++) {
            swap(arr[j], arr[a - (j - i)]);
        }
        for(int j = a; j > i; j--) arr[j] = arr[j - 1];
    }
    cout << ops.size() << '\n';
    for(auto x: ops) cout << x.fi << ' ' << x.se << '\n';
    
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x << '\n';

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