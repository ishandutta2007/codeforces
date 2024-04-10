#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#define N_ 301000
#define pii pair<int,int>
using namespace std;
int n, m, Q, P[201000], chk[301000], UF[201000], NN[201000];
vector<int>G[201000];
struct Edge{
    int a, b;
}Ed[301000];
struct Query{
    int ck, a;
}U[501000];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a]=Find(UF[a]);
}
int Where[201000], cnt;
int O[5100000], CCC[510000], cur;
set<pii>Z[201000];
void Merge(int a, int b, int c){
    a = Find(a),b=Find(b);
    if(a==b)return;
    if(a!=b){
        if(G[a].size()<G[b].size())swap(a,b);
        for(auto &t : G[b]){
 
            G[a].push_back(t);
            if(c<=Q){
                O[++cur] = t;
                CCC[c]++;
            }
        }
            G[b].clear();
        UF[b]=a;
    }
}
int main(){
    int i;
    scanf("%d%d%d",&n,&m,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&P[i]);
        G[i].push_back(i);
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&Ed[i].a,&Ed[i].b);
    }
    for(i=1;i<=Q;i++){
        scanf("%d%d",&U[i].ck,&U[i].a);
        if(U[i].ck==2)chk[U[i].a]=i;
    }
    for(i=1;i<=n;i++)UF[i]=i;
    for(i=1;i<=m;i++){
        if(!chk[i]){
            Merge(Ed[i].a,Ed[i].b, Q+1);
        }
    }
    for(i=Q;i>=1;i--){
        if(U[i].ck==2){
            int t = U[i].a;
            Merge(Ed[t].a,Ed[t].b,i);
        }
    }
    int cc=0;
    for(i=1;i<=n;i++)if(Find(i)==i)NN[i]=++cc;
    for(i=1;i<=n;i++){
        int x = NN[Find(i)];
        Z[x].insert({P[i],i});
        Where[i] = x;
    }
    cnt = cc;
    for(i=1;i<=Q;i++){
        if(U[i].ck==2){
            if(!CCC[i])continue;
            cnt++;
            for(int j=0;j<CCC[i];j++){
                int t = O[cur];
                Z[Where[t]].erase(Z[Where[t]].find({P[t],t}));
                Where[t] = cnt;
                Z[cnt].insert({P[t],t});
                cur--;
            }
        }
        else{
            int a = U[i].a;
            auto it = Z[Where[a]].end();it--;
            printf("%d\n",it->first);
            int v = it->second;
            P[v]=0;
            Z[Where[a]].erase(it);
            Z[Where[a]].insert({P[v],v});
        }
    }
}