//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 1E5+7;
int A[DIM];
void solve(){
    int n;
    cin>>n;
    ll res = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        res = max(res,ll(A[i])*A[i-1]);
    }
    cout<<res<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/**
1
6 3
111001
111100
10 3
1101000000
1011000000

**/