#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=100009;
int n,q,sz;
int rt[M];
int s[M*40],ls[M*40],rs[M*40];
vector<pii>v,nv;
void update(int la,int&now,int x,int o){
    now=++sz;
    s[now]=s[la]+1;
    ls[now]=ls[la];
    rs[now]=rs[la];
    if(o==-1)return;
    (x>>o&1)?update(rs[la],rs[now],x,o-1):update(ls[la],ls[now],x,o-1);
}
void work(){
    sz=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        update(rt[i-1],rt[i],x,29);
    }
    cin>>q;
    for(int i=1;i<=q;++i){
        int l,r;
        cin>>l>>r;
        v.clear();
        v.eb(rt[r],rt[l-1]);
        int ans=0;
        for(int j=29;j>=0;--j){
            int t=0;
            for(auto o:v){
                int x=o.fi,y=o.se;
                t+=s[ls[x]]-s[ls[y]];
            }
            if(t<=1){
                ans|=1<<j;
                for(auto o:v){
                    int x=rs[o.fi],y=rs[o.se];
                    if(x)nv.eb(x,y);
                    x=ls[o.fi],y=ls[o.se];
                    if(s[x]-s[y]==1){
                        nv.eb(x,y);
                    }
                }
            }
            else{
                for(auto o:v){
                    int x=ls[o.fi],y=ls[o.se];
                    if(x)nv.eb(x,y);
                }
            }
            v=nv;
            nv.clear(); 
        }
        cout<<ans<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1
4
0 2 1 1073741823
4
1 2
2 3
1 3
3 4


------+-++++--++++--



*/