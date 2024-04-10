#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define ull unsigned long long
#define endl '\n'
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define eb emplace_back 
#define ceil(x,y) (x+y-1)/y
#define deb(x) { cerr << #x << '=' << x << '\n'; }
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i <= 30; ++i){
        int cur = 0, minn = 0;
        for (int j = 0; j < n; ++j){
            int val = (a[j] > i ? -MOD : a[j]);
            cur += val;
            minn = min(cur, minn);
            res = max(res, (cur - minn) - i);
        }
    }
    cout << res;
}
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    solve();
}