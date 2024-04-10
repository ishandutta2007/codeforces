#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,u,v,k,w,a;
        cin>>x>>y>>u>>v>>k>>w>>a;
        y+=k*w;
        bool ans=false;
        for(int i=0;i<=k;i++)
        {
            if((u+y-1)/y<=(x+v-1)/v){ans=true;break;}
            x+=a;
            y-=w;

        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}