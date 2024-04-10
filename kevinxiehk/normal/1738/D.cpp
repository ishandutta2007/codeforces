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
vector<int> pre[100005];
bool cmp(int a, int b) {
    return pre[a].size() < pre[b].size();
}
void solve(int TC) {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) pre[i].clear();
    int arr[n + 5];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int k = 1;
    while(arr[k] > k && k <= n) k++;
    k--;
    for(int i = 1; i <= n; i++) {
        pre[arr[i] % (n + 1)].pb(i);
    }
    int curr = 0;
    cout << k << '\n';
    while(pre[curr].size() > 0) {
        sort(pre[curr].begin(), pre[curr].end(), cmp);
        int nn;
        for(auto x: pre[curr]) {
            cout << x << ' ';
            nn = x;
        }
        curr = nn;
    }
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