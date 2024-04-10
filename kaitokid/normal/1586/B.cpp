#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int fr[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<=n;i++)fr[i]=0;
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            fr[y]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++)if(fr[i]==0){ans=i;break;}
        for(int i=1;i<=n;i++)
        {
            if(ans!=i)cout<<ans<<" "<<i<<endl;
        }
    }
    return 0;
}