#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[3009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ans=0;
        for(int i=0;i<n;i++)
            {cin>>a[i];ans=max(ans,a[i]/k);}

        for(int g=1;g<=3000;g++)
        {
            int res=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]<g){res=100000;continue;}
                int d=a[i]/g;
                res=max(res,a[i]/min(d,k));
            }
            ans=min(res-g,ans);
           // cout<<g<<" "<<res<<endl;
        }
        cout<<ans<<endl;

    }
    return 0;
}