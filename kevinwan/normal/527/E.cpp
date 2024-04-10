//Oshvleiki Svlaiyoska Ranasku sachi
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e5+10;
const ll mod=1e9+7;
int u[mn],v[mn];
int to(int x,int i){return x^u[i]^v[i];}
vector<int>g[mn];
bool vise[mn],visv[mn];
int at[mn];
void go(int x){while(at[x]<g[x].size()&&vise[g[x][at[x]]])at[x]++;}
void hail(int x){
    stack<int>s;
    vector<int>pth;
    s.push(x);
    while(s.size()){
        int x=s.top();
        visv[x]=1;
        go(x);
        if(at[x]==g[x].size())pth.push_back(x),s.pop();
        else{
            int y=to(x,g[x][at[x]]);
            vise[g[x][at[x]]]=1;
            s.push(y);
        }
    }
    for(int i=0;i+1<pth.size();i++){
        if(i&1)printf("%d %d\n",pth[i],pth[i+1]);
        else printf("%d %d\n",pth[i+1],pth[i]);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(i);
        g[b].push_back(i);
        u[i]=a,v[i]=b;
    }
    int lo=-1;
    for(int i=1;i<=n;i++)if(g[i].size()&1){
        if(lo==-1)lo=i;
        else{
            u[m]=i,v[m]=lo;
            g[i].push_back(m);
            g[lo].push_back(m++);
            lo=-1;
        }
    }
    if(m&1)u[m]=v[m]=1,g[1].push_back(m++);
    printf("%d\n",m);
    for(int i=1;i<=n;i++)if(!visv[i])hail(i);
}