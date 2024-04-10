#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,q;
int a[M],b[M];
ll ans,sum;
ll c[M],d[M];
ll v[2][M],s[2][M],siz[2];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=2;i<=n;++i)c[i]=b[i]-a[i],d[i]=-1;
    for(int i=2;i<=n;++i){
        for(int j=i+i;j<=n;j+=i)c[j]-=c[i],d[j]-=d[i];
        if(d[i]==0)sum+=abs(c[i]);
        else if(d[i]==-1)v[0][++siz[0]]=c[i];
        else v[1][++siz[1]]=c[i];
    }
    sort(v[0]+1,v[0]+siz[0]+1);
    sort(v[1]+1,v[1]+siz[1]+1);
    for(int i=1;i<=siz[0];++i)s[0][i]=s[0][i-1]+v[0][i];
    for(int i=1;i<=siz[1];++i)s[1][i]=s[1][i-1]+v[1][i];
    cin>>q;
    for(int i=1;i<=q;++i){
        ll x;
        cin>>x;
        x=x-a[1];
        ans=sum+abs(x);
        int p=lower_bound(v[0]+1,v[0]+siz[0]+1,x)-v[0]-1;
        ans+=s[0][siz[0]]-s[0][p]-x*(siz[0]-p);
        ans+=x*p-s[0][p];
        x=-x;
        p=lower_bound(v[1]+1,v[1]+siz[1]+1,x)-v[1]-1;
        ans+=s[1][siz[1]]-s[1][p]-x*(siz[1]-p);
        ans+=x*p-s[1][p];
        cout<<ans<<endl;
    }
    return 0;
}