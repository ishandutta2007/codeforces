/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1],sum=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    sort(a+1,a+n+1);
    if(n==1)
    {
        cout<<"T"<<endl;
        return;
    }
    
    for(int i=1;i<=n;i++) sum+=a[i];
    
    if(a[n]*2>sum){ cout<<"T"<<endl; return; }
    
    if(sum%2==0) cout<<"HL"<<endl;
    else cout<<"T"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}