#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[109];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=1000000000;
        for(int u=0;u<=2;u++)
           for(int v=0;v<3;v++)
        {
            int res=0;
            for(int i=0;i<n;i++)
            {
                int tmp=1000000000;
                for(int uu=0;uu<=u;uu++)
                    for(int vv=0;vv<=v;vv++)
                {
                    int p=a[i]-uu-2*vv;
                    if(p>=0 && p%3==0)tmp=min(tmp,p/3);
                }

                res=max(res,tmp);
            }
            res+=u+v;
            ans=min(ans,res);
        }
       cout<<ans<<endl;
    }
    return 0;
}