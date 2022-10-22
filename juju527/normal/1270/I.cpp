#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxt=105;
int k,S,t;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int x[maxt],y[maxt];
struct matrix{
    vector<vector<ll> >x;
    void init(){
        x.resize(S);
        for(int i=0;i<S;i++)x[i].resize(S);
        return ;
    }
};
int main(){
    k=read();S=(1<<k);
    matrix F,G;
    G.init();
    for(int i=0;i<S;i++)for(int j=0;j<S;j++)G.x[i][j]=read();
    t=read();
    for(int i=1;i<=t;i++){x[i]=read()-1;y[i]=read()-1;}
    F.init();
    for(int b=0;b<k;b++){
        for(int i=0;i<S;i++)for(int j=0;j<S;j++)F.x[i][j]=0;
        for(int c=1;c<=t;c++){
            int u=x[c],v=y[c];
            for(int i=0;i<S;i++)
                for(int j=0;j<S;j++)
                    F.x[(i+u)&(S-1)][(j+v)&(S-1)]^=G.x[i][j];
        }
        G=F;
        for(int c=1;c<=t;c++)x[c]=(x[c]+x[c])&(S-1),y[c]=(y[c]+y[c])&(S-1);
    }
    int res=0;
    for(int i=0;i<S;i++)for(int j=0;j<S;j++)if(G.x[i][j])res++;
    printf("%d\n",res);
    return 0;
}