#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct edge{
    int u,v,w;
    inline friend bool operator <(edge a,edge b){
        return a.w < b.w;
    }
};

int N,M,K,W,i,j,k,l,c,ec,sol;
char A[1005][15][15];

edge E[555555];
vector <int> O[1005];

int P[1005],Sz[1005];

void init(){
    int i;
    for (i=1; i<=K+1; i++){
        P[i] = i;
        Sz[i] = 1;
    }
}

int endparent(int a){
    while (a!=P[a]) a = P[a];
    return a;
}

void dodaj(int a0,int b0,int w){
    int a,b;
    a = endparent(a0);
    b = endparent(b0);
    if (a==b) return;
    //printf("%d %d\n",a0,b0);
    O[a0].push_back(b0);
    O[b0].push_back(a0);
    sol += w;
    if (Sz[a] < Sz[b]){
        P[a] = b;
        Sz[b] += Sz[a];
    } else {
        P[b] = a;
        Sz[a] += Sz[b];
    }
}

void dfs(int x,int odakle){
    int i,y;
    if (x <= K) printf("%d %d\n",x,odakle!=K+1?odakle:0);
    for (i=0; i<O[x].size(); i++){
        y = O[x][i];
        if (y != odakle) dfs(y,x);
    }
}

int main(){
    //ulaz
    scanf("%d%d%d%d",&N,&M,&K,&W);
    init();
    for (i=1; i<=K; i++){
        for (j=1; j<=N; j++){
            scanf("%s",A[i][j]+1);
        }
    }
    //ucitavanje grana
    for (i=1; i<=K; i++){
        for (j=i+1; j<=K; j++){
            c = 0;
            for (k=1; k<=N; k++){
                for (l=1; l<=M; l++){
                    if (A[i][k][l] != A[j][k][l]) c++;
                }
            }
            ec++;
            E[ec].u = i;
            E[ec].v = j;
            E[ec].w = c*W;
        }
    }
    for (i=1; i<=K; i++){
        ec++;
        E[ec].u = i;
        E[ec].v = K+1;
        E[ec].w = N*M;
    }
    //kruskal
    sort(E+1,E+ec+1);
    for (i=1; i<=ec; i++){
        //printf("dodavam %d %d %d\n",E[i].u,E[i].v,E[i].w);
        dodaj(E[i].u,E[i].v,E[i].w);
    }
    printf("%d\n",sol);
    dfs(K+1,K+1);
    return 0;
}