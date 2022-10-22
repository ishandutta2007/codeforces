#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int maxn=2e5+5;
const db eps=1e-9;
int a[maxn],b[maxn];
struct node{
    ll u,v;
    node operator +(node i)const{return (node){u+i.u,v+i.v};}
    node operator -(node i)const{return (node){u-i.u,v-i.v};}
};
node p[maxn];
struct pi{
    double fi;
    int se;
    bool operator <(pi i)const{return (fabs(fi-i.fi)<=eps)?se<i.se:fi<i.fi;}
};
vector<pi> f,g;
node sumf,sumg;
node pref[maxn],sufg[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    p[1]=(node){1,-a[1]};
    f.push_back((pi){a[1],1});
    for(int i=2;i<=n;i++)p[i].v=a[i],p[i]=p[i]+p[1];
    ll ans=0;
    for(int i=2;i<=n;i++){
        p[i]=(node){0,b[i]}-p[i];
        ll u=p[i].u,v=p[i].v;
        if(u==0)ans+=abs(v);
        else if(u>0)f.push_back((pi){-1.0*v/u,i});
        else g.push_back((pi){-v/u,i});
        for(int j=i+i;j<=n;j+=i)p[j]=p[j]+p[i];
    }
    sort(f.begin(),f.end());sort(g.begin(),g.end());
    for(int i=0;i<f.size();i++)pref[i]=(i?pref[i-1]:(node){0,0})+p[f[i].se];
    for(int i=g.size()-1;i>=0;i--)sufg[i]=sufg[i+1]+p[g[i].se];
    sumf=pref[f.size()-1],sumg=sufg[0];
    int Q;
    Q=read();
    while(Q--){
        int x;
        x=read();
        int posf=upper_bound(f.begin(),f.end(),(pi){x,0})-f.begin()-1;
        int posg=lower_bound(g.begin(),g.end(),(pi){x,0})-g.begin();
        node res,tmp;
        if(posf>=0)tmp=pref[posf];else tmp=(node){0,0};
        res=res+tmp+tmp-sumf;
        tmp=sufg[posg];
        res=res+tmp+tmp-sumg;
        printf("%lld\n",res.u*x+res.v+ans);
    }
    return 0;
}