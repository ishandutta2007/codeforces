#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAXN 131072
#define OFFS 131071
using namespace std;

int N,M,K;
vector <int> E[100005];
vector <long long> W[100005];

int Z[100005];
long long ZW[100005];

void ucitaj(){
    scanf("%d%d%d",&N,&M,&K);
    int i,j,x,y,w;
    for (i=1; i<=M; i++){
        scanf("%d%d%d",&x,&y,&w);
        E[x].push_back(y);
        E[y].push_back(x);
        W[x].push_back(w);
        W[y].push_back(w);
    }
    for (i=1; i<=K; i++){
        scanf("%d%d",&y,&w);
        E[1].push_back(y);
        E[y].push_back(1);
        W[1].push_back(w);
        W[y].push_back(w);
        Z[i] = y;
        ZW[i] = w;
    }
}

long long D[MAXN],Bw[MAXN];
bool V[MAXN];
int Tree[2*MAXN];

int boljicvor(int a,int b){
    if (!V[a] && !V[b]) return -1;
    if (V[a] && !V[b]) return a;
    if (!V[a] && V[b]) return b;
    if (D[a] < D[b]) return a;
    return b;
}

void init_tree(){
    int i;
    for (i=1; i<=MAXN; i++) D[i] = 123456789123456789ll;
    for (i=1; i<=N; i++) V[i] = true;
    for (i=MAXN; i<2*MAXN; i++) Tree[i] = i-OFFS;
    for (i=OFFS; i>=1; i--) Tree[i] = boljicvor(Tree[2*i],Tree[2*i+1]);
}

void run(int x){
    x+=OFFS;
    while (x>1){
        x /= 2;
        Tree[x] = boljicvor(Tree[2*x] , Tree[2*x+1]);
    }
}

void update(int x,long long dst,long long w){
    if (dst >= D[x]) return;
    D[x] = dst;
    Bw[x] = w;
    run(x);
}

int In[100005];

void dijkstra(){
    int i,j,k;
    update(1,0,0);
    while (Tree[1] != -1){
        k = Tree[1];
        V[k] = false;
        run(k);
        for (i=0; i<E[k].size(); i++) update(E[k][i],D[k] + W[k][i],W[k][i]);
    }
    for (k=1; k<=N; k++){
        for (i=0; i<E[k].size(); i++) if (D[k] + W[k][i] == D[E[k][i]]) In[E[k][i]]++;
    }
    k = 0;
    for (i=1; i<=K; i++) if (ZW[i] == D[Z[i]]){
        if (In[Z[i]]>1){
            k++;
            In[Z[i]]--;
        }
    }
    for (i=1; i<=K; i++) if (ZW[i] > D[Z[i]]) k++;
    printf("%d\n",k);
}

int main(){
    ucitaj();
    init_tree();
    dijkstra();
    return 0;
}