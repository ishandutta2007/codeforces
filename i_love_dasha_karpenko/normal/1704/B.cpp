//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define int ll
const int N = 2e5+7;
int A[N];
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i = 1;i<=n;i+=1){
        cin>>A[i];
    }
    int res = 0;
    int l = A[1],r = A[1];
    for(int i = 2;i<=n;i+=1){
        l = min(l,A[i]);
        r = max(r,A[i]);
        if (r-l>x*2){
            l = r = A[i];
            res += 1;
        }
    }
    cout<<res<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}