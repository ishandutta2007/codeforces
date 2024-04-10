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
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int ta = 0;
    priority_queue<int> da;
    int freq[n + 5];
    for(int i = 0; i <= n; i++) freq[i] = 0;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    bool died = false;
    vector<int> ans;
    for(int i = 0; i <= n; i++) {
        if(died) {
            ans.pb(-1);
            continue;
        }
        if(i > 0) {
            if(freq[i - 1] == 0) {
                if(da.empty()) {
                    ans.pb(-1);
                    died = true;
                    continue;
                }
                ta += i - 1 - da.top();
                da.pop();
            }
        }
        for(int _ = 1; _ < freq[i]; _++) da.push(i);
        ans.pb(freq[i] + ta);
    }
    for(auto x: ans) cout << x << ' ';
    cout << '\n';
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