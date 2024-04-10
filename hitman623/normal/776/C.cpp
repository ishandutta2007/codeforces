#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,a[100005]={0},k,i,j,p[100005]={0},po[100]={0},m,t=1,l=0,ans=0;
    map < long long , long> s;
    cin>>n>>k;
    p[-1]=0;
    for(i=0;i<n;++i)
        {cin>>a[i];
        p[i]=a[i]+p[i-1];}
    m=pow(10,15);
    if(k!=1 && k!=-1)
    while(t<=m)
    {
       po[l++]=t;
       t*=k;
    }
    else
    {
        if(k==1)
    {
        po[l++]=1;
    }
    else
    {
        po[l++]=-1;
        po[l++]=1;
    }
    }
    for(i=0;i<l;++i)
    {
        s.clear();
        for(j=0;j<n;++j)
        {
            ans+=s[p[j]-po[i]];
            if(p[j]==po[i]) ans++;
            s[p[j]]++;
        }
    }
    cout<<ans;
    return 0;
}