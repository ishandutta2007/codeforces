//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 1E5+7;
ll A[N];
void solve(){
    int n;
    cin>>n;
    ll sum = 0;
    for(int i = 1;i<=n;++i) {
        cin>>A[i];
        sum+=A[i];
    }
    sort(A+1,A+1+n);
    ll cur = 0;
    ld res = -ll(n)*(1E9);
    for(int i = 1;i<n;++i){
        cur+=A[i];
        sum-=A[i];
        res = max(res,ld(cur)/i+ld(sum)/(n-i));
    }
    cout<<fixed<<setprecision(10)<<res<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    //t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}