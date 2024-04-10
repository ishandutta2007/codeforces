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

        int n;
        cin>>n;
        int mx=-1,x,y,r;
        for(int i=3;i<=n;i++)
        {
            cout<<"? "<<1<<" "<<2<<" "<<i<<endl;
            fflush(stdout);
            int u;
            cin>>u;
            if(u>mx){mx=u;x=i;}

        }
        vector<int>v;
        for(int i=1;i<=n;i++)if(i!=x)v.push_back(i);
        mx=-1;
        for(int i=0;i+1<v.size();i+=2)
        {
            cout<<"? "<<x<<" "<<v[i]<<" "<<v[i+1]<<endl;
            fflush(stdout);
            int u;
            cin>>u;
            if(u>mx){mx=u;y=v[i];r=v[i+1];}
        }
        int d=v.size();
        if(d%2)
        {
            cout<<"? "<<x<<" "<<v[d-2]<<" "<<v[d-1]<<endl;
            fflush(stdout);
            int u;
            cin>>u;
            if(u>mx){mx=u;y=v[d-1];r=v[d-2];}
        }

        int g=1;
        for(int i=1;i<=4;i++)if((i!=x) && (i!=y) && (i!=r)){g=i;break;}
        cout<<"? "<<g<<" "<<x<<" "<<y<<endl;
        fflush(stdout);
            int u;
            cin>>u;
            if(u==mx){cout<<"! "<<x<<" "<<y<<endl;fflush(stdout);continue;}

        cout<<"? "<<g<<" "<<x<<" "<<r<<endl;
        fflush(stdout);
            cin>>u;
            if(u==mx){cout<<"! "<<x<<" "<<r<<endl;fflush(stdout);continue;}
        cout<<"! "<<y<<" "<<r<<endl;
        fflush(stdout);

               }
    return 0;
}