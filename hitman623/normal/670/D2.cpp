#include <bits/stdc++.h>

using namespace std;
bool cmp( pair<long long,long long> a, pair <long long,long long> b)
{
    return(a.second<b.second);
}
long long n,k,a[200005],b[200005],i,p[200005][2]={0},ans=0,e=0;
int main()
{
    vector < pair<long long,long long> > c;
    cin>>n>>k;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n;++i)
        cin>>b[i];
    for(i=0;i<n;++i)
    {
        c.push_back(make_pair(i,b[i]/a[i]));
    }
    sort(c.begin(),c.end(),cmp);
    ans=c[0].second;
    p[0][1]=a[c[0].first];
    for(i=0;i<n;++i)
    {
        p[i][0]=a[c[i].first]-b[c[i].first]%a[c[i].first];
        if(i>0)
        {p[i][0]+=p[i-1][0];
        p[i][1]=a[c[i].first]+p[i-1][1];}
    }
       // for(i=0;i<n;++i)
       // cout<<c[i].first<<" "<<c[i].second<<" "<<p[i][0]<<" "<<p[i][1]<<endl;
    for(i=0;i<n-1;++i)
    {
        if(c[i+1].second>c[i].second)
        {
             if(p[i][0]+e<=k)
        {
            k-=p[i][0]+e;ans++;
            c[i].second++;
            if((c[i+1].second-c[i].second)*p[i][1]<=k)
            {
                k-=(c[i+1].second-c[i].second)*p[i][1];
                ans+=(c[i+1].second-c[i].second);
            }
            else
            {
                ans+=k/p[i][1];
                k=0;
                break;
            }
            e=p[i][1]-p[i][0];
        }
        else break;
        }
        //p[i]=a[c[i].first]+a[c[i-1].first];
    }
    ans+=k/p[n-1][1];
    if(ans<0) ans=0;
    cout<<ans;
    return 0;
}