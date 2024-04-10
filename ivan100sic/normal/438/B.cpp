#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct edge{
    int snaga,x,y;
    inline friend bool operator <(edge a,edge b){
        return a.snaga > b.snaga;
    }
};

edge A[100005];
int P1[100005],P2[100005],N,M;
int Snaga[100005];

void ucitaj(){
    int i,j,x,y,w;
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++) scanf("%d",Snaga+i);
    for (i=1; i<=M; i++){
        scanf("%d%d",&x,&y);
        w = min(Snaga[x],Snaga[y]);
        A[i].x = x;
        A[i].y = y;
        A[i].snaga = w;
    }
}

int Parent[100005],Size[100005];
long long sol;

void spremi(){
    int i;
    for (i=1; i<=N; i++){
        Parent[i] = i;
        Size[i] = 1;
    }
}

int endparent(int x){
    while (Parent[x] != x) x = Parent[x];
    return x;
}

bool spojivi(int a,int b){
    return endparent(a) != endparent(b);
}

void spoji(int a,int b,int ew){
    if (!spojivi(a,b)) return;
    a = endparent(a);
    b = endparent(b);
    //printf("%d %d %d %d\n",Size[a],Size[b],a,b);
    sol += 1ll * Size[a] * Size[b] * ew;
    if (Size[a] < Size[b]){
        Parent[a] = b;
        Size[b] += Size[a];
    } else {
        Parent[b] = a;
        Size[a] += Size[b];
    }
}

int main(){
    ucitaj();
    spremi();
    int i,j,k,x;
    sort(A+1,A+M+1);
    for (i=1; i<=M; i++){
        spoji(A[i].x,A[i].y,A[i].snaga);
    }
    printf("%.9lf\n",sol / (0.5*N*(N-1)));
    return 0;
}