#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<int,int> >v;
ll res;

int ans[20000009],pr[20000009];
int c,d,x,g;
void ch(int i)
{
    if(x%i)return;
    int r=x/i;
    r+=d;
    if(r%c)return;
    r/=c;
    res=res+ans[r];
}
void go(int x)
{
    if(x==v.size()){ch(g);return;}
    go(x+1);
    for(int i=0;i<v[x].second;i++)
    {
        g*=v[x].first;
        go(x+1);
    }
 for(int i=0;i<v[x].second;i++)g/=v[x].first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<=20000000;i++)ans[i]=1,pr[i]=i;
    for(int i=2;i<=20000000;i++)
    {
        if(ans[i]!=1)continue;
        for(int j=i;j<=20000000;j+=i)ans[j]*=2,pr[j]=i;
    }
    int t;
    cin>>t;
    while(t--)
    {
        cin>>c>>d>>x;
         res=0;
        v.clear();
        int z=x;
        while(z>1)
        {
            int u=pr[z],h=0;
            while(z%u==0){z/=u;h++;}
            v.push_back({u,h});
        //cout<<u<<" "<<h<<endl;
        }
        g=1;
        go(0);
        cout<<res<<endl;
    }
    return 0;
}