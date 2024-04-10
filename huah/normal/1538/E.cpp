#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
//typedef __int128 ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=1e5+5,mod=998244353,G=3,Gi=332748118;
int t,n;
map<string,pair<string,ll>>vis;
int cal(string &y)
{
    int sum=0;
    for(int i=0;i+3<y.size();i++)
    if(y[i]=='h'&&y[i+1]=='a'&&y[i+2]=='h'&&y[i+3]=='a') sum++;
    return sum;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        vis.clear();
        cin>>n;
        string las;
        while(n--)
        {
            string x,op,y,z;
            cin>>x>>op;
            if(op==":=")
            {
                cin>>y;
                ll sum=cal(y);
                if(y.size()<6) vis[x]={y,sum};
                else
                {
                    z="";
                    z+=y[0]+y[1]+y[2]+y[y.size()-1]+y[y.size()-2]+y[y.size()-3];
                    vis[x]={z,sum};
                }
            }
            else
            {
                cin>>y>>z>>z;
                ll sum=vis[y].second+vis[z].second;
                y=vis[y].first;z=vis[z].first;
                string t="";
                for(int i=max(0,int(y.size())-3);i<y.size();i++) t+=y[i];
                for(int i=0;i<min(3,int(z.size()));i++) t+=z[i];
                sum+=cal(t);
                t="";
                for(int i=0;i<min(3,int(y.size()));i++) t+=y[i];
                for(int i=max(0,int(z.size())-3);i<z.size();i++) t+=z[i];
                vis[x]={t,sum};
            }
            las=x;
        }
        printf("%lld\n",vis[las].second);
    }
}