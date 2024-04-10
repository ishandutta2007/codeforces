#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, K, w[501000], CK[501000], UF[501000];
vector<int>G[501000], T[501000], Z[501000];
struct Edge{
    int a, b;
    int c, d;
    bool operator <(const Edge &p)const{
        return c!=p.c?c<p.c:d<p.d;
    }
};
vector<Edge>E;
vector<int>AA[3];
int Col[501000], chk = 0;
void DFS(int a, int col){
    Col[a]=col;
    AA[col].push_back(a);
    for(auto &t : T[a]){
        if(Col[t]){
            if(Col[t]+Col[a]!=3)chk=1;
        }
        else{
            DFS(t,3-col);
        }
    }
}
int Find(int a){
    if(a==UF[a])return a;
    return UF[a]=Find(UF[a]);
}
void Add_Edge(int a, int b){
    Z[a].push_back(b);
    Z[b].push_back(a);
}
int v[501000],ckck;
void DFS2(int a, int col, int cur){
    v[a]=cur;
    Col[a]=col;
    for(auto &t : Z[a]){
        if(v[t]==cur){
            if(Col[t]+Col[a]!=3)ckck=1;
        }
        else{
            DFS2(t,3-col,cur);
        }
    }
}
bool Bipartite(int a, int cur){
    //puts("BB");
    if(v[a]==cur)return true;
    ckck=0;
    DFS2(a,1,cur);
    return ckck==0;
}
int main(){
    int i;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=n;i++){
        UF[i]=i;
        scanf("%d",&w[i]);
        G[w[i]].push_back(i);
    }
    for(i=0;i<m;i++){
        int a, b;
        scanf("%d%d",&a,&b);
            if(w[a]>w[b])swap(a,b);
        if(w[a]==w[b]){
            T[a].push_back(b);
            T[b].push_back(a);
        }
        else{
            E.push_back({a,b,w[a],w[b]});
        }
    }
   // puts("!!");
    sort(E.begin(),E.end());
    for(i=1;i<=n;i++){
      //  printf("%d\n",i);
        if(!Col[i]){
            chk=0;
            AA[1].clear(), AA[2].clear();
            DFS(i,1);
            if(chk){
                CK[w[i]]=1;
                continue;
            }
            if(AA[1].empty()||AA[2].empty())continue;
            for(auto &t: AA[1])UF[t]=AA[1][0];
            for(auto &t: AA[2])UF[t]=AA[2][0];
            Add_Edge(AA[1][0],AA[2][0]);
        }
    }
    //puts("???");
    long long res=0;
    int cc=0;
    for(i=1;i<=K;i++){
        if(!CK[i])cc++;
    }
    res=1ll*cc*(cc-1)/2;
    for(i=0;i<E.size();i++){
        if(CK[E[i].c]||CK[E[i].d])continue;
        int j;
        vector<int>TP;
        for(j=i;j<E.size() && E[j].c==E[i].c&&E[j].d==E[i].d;j++){
            int x = Find(E[j].a), y = Find(E[j].b);
            Z[x].push_back(y);
            Z[y].push_back(x);
        }


        for(j=i;j<E.size() && E[j].c==E[i].c&&E[j].d==E[i].d;j++){
            int x = Find(E[j].a), y = Find(E[j].b);
            if(!Bipartite(x,i+1)){
                res--;
                break;
            }
        }


        for(j=i;j<E.size() && E[j].c==E[i].c&&E[j].d==E[i].d;j++){
            int x = Find(E[j].a), y = Find(E[j].b);
            Z[x].pop_back();
            Z[y].pop_back();
        }
        i=j-1;
    }
    printf("%lld\n",res);
}