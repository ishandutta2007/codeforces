#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
struct frac{
    int a,b;
    bool operator<(frac ot){return 1LL*a*ot.b<1LL*b*ot.a;}
};
vector<int>g[mn];
int num[mn];
int rem[mn];
bool in[mn];
int ansa=-1,ansb=0x3f3f3f3f,bes;
struct comp{
    bool operator()(int a,int b){
        ll d=1LL*num[a]*g[b].size()-1LL*num[b]*g[a].size();
        if(d)return d<0;
        return a<b;
    }
};
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        num[x]=-1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!num[i])num[i]=g[i].size();
    set<int,comp>s;
    for(int i=1;i<=n;i++)s.insert(i),in[i]=1;
    for(int i=n;i;i--){
        int x=*s.begin();
        if(1LL*num[x]*ansb>1LL*ansa*((ll)g[x].size()))ansa=num[x],ansb=g[x].size(),bes=i;
        in[x]=0;
        rem[i]=x;
        s.erase(x);
        for(int y:g[x])if(in[y]){
            s.erase(y);
            num[y]--;
            s.insert(y);
        }
    }
    printf("%d\n",bes);
    for(int i=1;i<=bes;i++)printf("%d ",rem[i]);
}