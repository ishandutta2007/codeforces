#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
void solve(){
   ll n,m,k;
   cin>>n>>m>>k;
   bool f1 = 1,f2 = 1;
   bool c = 0;
   ll s1 = 0,s2 = 0;
   ll sum = 0;
   int cnt1 = 0,cnt2 = 0;
   for(int i = 1;i<=k;i+=1){
        ll val;
        cin>>val;
        if (val/m>=2){
            s1 += val/m;
            cnt1 += val/m > 2;
        }
        if (val/n>=2){
            s2 += val/n;
            cnt2 += val/n > 2;
        }
        if (val>=n*m){
            c = 1;
        }
   }
   f1 = min(f1,s1>=n);
   f2 = min(f2,s2>=m);
   f1 = min(f1,n>=4);
   f2 = min(f2,m>=4);
   f1 = min(f1,n%2==0 || cnt1>0);
   f2 = min(f2,m%2==0 || cnt2>0);
 // cout<<f1<<' '<<f2<<endl;
   cout<<((f1 || f2 || c)?"Yes\n":"No\n");
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