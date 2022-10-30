#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int N = 2e5+7;
int A[N];
ll pref[N];
void solve() {
    ll  n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    sort(A+1,A+1+n);
    for(int i = 1;i<=n;++i){
        pref[i] = pref[i-1]+A[i];
    }
    ll res = pref[n];
    for(int i = 1;i<=n;++i){
        ll val = (k-pref[i]+A[1])/(n-i+1);
        while (val*(n-i+1)+pref[i]-A[1]>k)
            --val;
        res = min(res,max(0ll,A[1]-val)+(n-i));
    }
    cout<<res<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}