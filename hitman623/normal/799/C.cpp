#include <bits/stdc++.h>
#define pb push_back
#define S second
#define F first
using namespace std;
long n,m,b[200005],p[200005],i,c,d,mx[2][200005],mxx[2][200005],s1,s2,beauty=0,u,l,h=1e9+7,w=0;
vector < pair < long ,long > > v[2];
pair < long ,long > pr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char ch;
    cin>>n>>c>>d;
    for(i=0;i<n;++i)
    {
        cin>>b[i]>>p[i]>>ch;
        if(ch=='C') v[0].pb({p[i],b[i]});
        else v[1].pb({p[i],b[i]});
    }
    s1=v[0].size();
    s2=v[1].size();
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    if(s1>0)
    {
    mx[0][0]=v[0][0].S;
    mxx[0][0]=0;
    for(i=1;i<s1;++i)
    {
        if(mx[0][i-1]<v[0][i].S)
        {
            mxx[0][i]=mx[0][i-1];
            mx[0][i]=v[0][i].S;
        }
        else if(v[0][i].S>mxx[0][i-1])
        {
            mxx[0][i]=v[0][i].S;
            mx[0][i]=mx[0][i-1];
        }
        else
        {
            mx[0][i]=mx[0][i-1];
            mxx[0][i]=mxx[0][i-1];
        }
    }
    }
    if(s2>0)
    {
    mx[1][0]=v[1][0].S;
    mxx[1][0]=0;
    for(i=1;i<s2;++i)
    {
        if(mx[1][i-1]<v[1][i].S)
        {
            mxx[1][i]=mx[1][i-1];
            mx[1][i]=v[1][i].S;
        }
        else if(v[1][i].S>mxx[1][i-1])
        {
            mx[1][i]=mx[1][i-1];
            mxx[1][i]=v[1][i].S;
        }
        else
        {
            mx[1][i]=mx[1][i-1];
            mxx[1][i]=mxx[1][i-1];
        }
    }
    }
    for(i=s1-1;i>=0;i--)
    {
        if(v[0][i].F<=c)
        {
            l=c-v[0][i].F;
            pr={l,h};
            u=upper_bound(v[0].begin(),v[0].end(),pr)-v[0].begin();
            if(u>0)
            {
                if(mx[0][u-1]==v[0][i].S )
                {
                    if(u>=2)
                    beauty=max(beauty,v[0][i].S+mxx[0][u-1]);
                }
                else
                beauty=max(beauty,v[0][i].S+mx[0][u-1]);
            }
        }
    }
    for(i=s2-1;i>=0;i--)
    {
        if(v[1][i].F<=d)
        {
            l=d-v[1][i].F;
            pr={l,h};
            u=upper_bound(v[1].begin(),v[1].end(),pr)-v[1].begin();
            if(u>0)
            {
                if(mx[1][u-1]==v[1][i].S)
                {
                    if(u>=2)
                    beauty=max(beauty,v[1][i].S+mxx[1][u-1]);
                }
                else
                beauty=max(beauty,v[1][i].S+mx[1][u-1]);
            }
        }
    }
    pr={c,h};
    l=upper_bound(v[0].begin(),v[0].end(),pr)-v[0].begin();
    pr={d,h};
    u=upper_bound(v[1].begin(),v[1].end(),pr)-v[1].begin();
    if(l>0 && u>0)
    cout<<max(beauty,mx[0][l-1]+mx[1][u-1]);
    else cout<<beauty;
    return 0;
}