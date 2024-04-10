/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e6 + 5;
bool Prime[N];

int Make_Prime()
{
    for(int i=1;i<N;i++) Prime[i]=1;
    for(int i=2;i*i<N;i++) { if(Prime[i]==1) for(int j=i*i;j<N;j+=i) Prime[j]=0; }
    return 0;
}
int Implement_Make_Prime=Make_Prime();


void solve()
{
    int n, e;
    cin>>n>>e;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans=0;
    for(int i=1; i<=e; i++)
    {
        int l1=0, l2=0, found=0;;

        for(int j=i; j<=n; j+=e)
        {
            //cout<<a[j]<<" "<<Prime[a[j]]<<endl;
            if(Prime[a[j]]==0) { l1=0; l2=0; continue; }

            if(a[j]==1)
            {
                if(found) ans+=(l2-l1);
                l1++;
                l2++;
            }
            else
            {
                found=1;
                ans+=l1;
                l2=l1+1;
                l1=0;
            }
        }
        //cout<<i<<" "<<ans<<endl;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}