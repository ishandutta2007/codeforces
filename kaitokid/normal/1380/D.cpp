#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,k,x,y;
ll ans,p[200009],b[200009],a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    cin>>x>>k>>y;
    int u;
    for(int i=0;i<n;i++){cin>>u;a[i]=u;p[u]=i;}
    cin>>b[0];
    int d=p[b[0]];
    ll l=0;
    for(int i=0;i<d;i++)l=max(l,a[i]);
    ll res=-1;
    if(l<b[0])res=y*p[b[0]];
        if(p[b[0]]>=k){ll z=(p[b[0]]%k)*y;z+=(p[b[0]]/k-1)*min(x,y*k);z+=x;if(res==-1)res=z;res=min(res,z);}
        if(res==-1){cout<<-1;return 0;}
        ans+=res;
    for(int i=1;i<m;i++)
    {

        res=-1;
        cin>>b[i];
        if(p[b[i]]<p[b[i-1]]){cout<<-1;return 0;}
l=0;
for(int j=p[b[i-1]]+1;j<p[b[i]];j++)l=max(l,a[j]);
if(l<max(b[i],b[i-1]))res=y*(p[b[i]]-p[b[i-1]]-1);
if((p[b[i]]-p[b[i-1]]-1)>=k){ll z=((p[b[i]]-p[b[i-1]]-1)%k)*y;z+=x;z+=((p[b[i]]-p[b[i-1]]-1)/k-1)*min(x,y*k);
if(res==-1)res=z;res=min(res,z);}
        if(res==-1){cout<<-1;return 0;}
        ans+=res;
    }
    l=0;
    for(int i=p[b[m-1]]+1;i<n;i++)l=max(l,a[i]);
     res=-1;
    if(l<b[m-1])res=y*(n-1-p[b[m-1]]);
        if((n-1-p[b[m-1]])>=k){ll z=((n-1-p[b[m-1]])%k)*y;z+=((n-1-p[b[m-1]])/k-1)*min(x,y*k);z+=x;if(res==-1)res=z;res=min(res,z);}
        if(res==-1){cout<<-1;return 0;}
        ans+=res;
        cout<<ans<<endl;
        return 0;
}