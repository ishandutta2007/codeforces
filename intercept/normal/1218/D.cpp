#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod1=1e9+7;
const int mod2=1e9+87;
int kpow(int x,int y,int p,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%p)if(y&1)rex=1ll*x*rex%p;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=1e5+9;
const int S=1<<17;
const int N=S+9;
int n,m;
vector<pii>g[M];
int a[45][N],b[45][N],ans1[N],ans2[N];
void XO(int *dp,int o,int p){
    for(int k=1;k<S;k<<=1){
        for(int i=0;i<S;i+=k<<1){
            for(int j=0;j<k;++j){
                int x=dp[i+j],y=dp[i+j+k];
                if(o==1){
                    dp[i+j]=(dp[i+j]+y)%p;
                    dp[i+j+k]=(x+p-dp[i+j+k])%p;
                }
                else{
                    dp[i+j]=1ll*(dp[i+j]+y)%p*o%p;
                    dp[i+j+k]=1ll*(x-dp[i+j+k]+p)%p*o%p;
                }
            }
        }
    }
}
int top,num;
pii s[M];
bool vis[M],in[M];
void dfs(int u){
    vis[u]=1;
    in[u]=1;
    for(auto o:g[u]){
        int v=o.fi,w=o.se;
        if(!vis[v]){
            s[++top]=o;
            dfs(v);
            top--;
        }
        else if(in[v]&&v!=s[top-1].fi){
            num++;
            a[num][w]++;
            b[num][w]++;
            for(int i=top;i>=1;--i){
                if(s[i].fi==v)break;
                a[num][s[i].se]++;
                b[num][s[i].se]++;
            }
            XO(a[num],1,mod1);
            XO(b[num],1,mod2);
            
        }
    }
    in[u]=0;
}
int main(){
    scanf("%d%d",&n,&m);
    int sum=0;
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].eb(v,w);
        g[v].eb(u,w);
        sum^=w;
    }
    ans1[0]=ans2[0]=1;
    XO(ans1,1,mod1);
    XO(ans2,1,mod2);
    s[++top]=make_pair(1,0);
    dfs(1);
    for(int i=0;i<S;++i){
        int pp1=1,pp2=1;
        for(int j=1;j<=num;++j){
            pp1=1ll*pp1*a[j][i]%mod1;
            pp2=1ll*pp2*b[j][i]%mod2;
        }
        ans1[i]=pp1;
        ans2[i]=pp2;
    }
    XO(ans1,kpow(2,mod1-2,mod1),mod1);
    XO(ans2,kpow(2,mod2-2,mod2),mod2);
    for(int i=0;i<S;++i){
        if(ans1[sum^i]||ans2[sum^i]){
            printf("%d %d\n",i,ans1[sum^i]);
            break;
        }
    }
    
    return 0;
}