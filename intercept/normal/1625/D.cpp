#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=3e5+9;
int n,k,sz,lim=-1,ans;
int a[M],c[M*30][2],p[M*30],b[M*30],d[M];
vector<int>s;
int main(){
    cin>>n>>k;
    if(k==0){
        cout<<n<<endl;
        for(int i=1;i<=n;++i)cout<<i<<" ";
        return 0;
    }
    for(int i=0;i<30;++i){
        if(k>>i&1)lim=i;
    }
    for(int i=1;i<=n;++i){
        cin>>a[i];
        int u=0,v=0,x=0;
        for(int j=29;j>=0;--j){
            int o=a[i]>>j&1;
            if(!c[u][o])c[u][o]=++sz;
            u=c[u][o];
            if(j==lim+1)v=u;
        }
        d[i]=v;
        p[u]=i;
        u=v;
        for(int j=lim;j>=0;--j){
            int o=a[i]>>j&1;
            if(c[u][o^1])u=c[u][o^1],x|=1<<j;
            else u=c[u][o];
        }
        if(x>=k&&!b[v]){
            s.eb(i);
            s.eb(p[u]);
            b[v]=1;
        }
    }
    for(int i=1;i<=n;++i){
        if(!b[d[i]]&&a[i]>=k)s.eb(i),b[d[i]]=1;
    }
    for(int i=1;i<=n;++i){
        if(!b[d[i]]&&a[i]<k&&s.size())s.eb(i),b[d[i]]=1;
    }
    cout<<((s.size()==0)?-1:(int)s.size())<<endl;
    for(auto o:s)cout<<o<<" ";
    return 0;
}