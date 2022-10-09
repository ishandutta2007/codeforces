#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int P[200005],Sz[200005],A[200005],N;
bool U[200005];

void init(){
    for (int i=1; i<=N; i++){
        P[i] = i;
        Sz[i] = 1;
    }
}

int endparent(int x){
    while (x!=P[x]) x = P[x];
    return x;
}

bool spoji(int a,int b){
    a = endparent(a);
    b = endparent(b);
    if (a==b) return false;
    if (Sz[a] > Sz[b]) swap(a,b);
    P[a] = b;
    Sz[b] += Sz[a];
    return true;
}

int L[200005];

void ubaci(int x){
    //printf("ubacij %d\n",x);
    U[x] = true;
    if (U[x-1]) spoji(x,x-1);
    if (U[x+1]) spoji(x,x+1);

    L[Sz[endparent(x)]] = max(L[Sz[endparent(x)]] , A[x]);
    //printf("sz > %d : %d (%d)\n",Sz[endparent(x)],L[Sz[endparent(x)]],A[x]);
}

pair<int,int> B[200005];

int main(){
    scanf("%d",&N);
    for (int i=1; i<=N; i++) scanf("%d",A+i);
    init();
    for (int i=1; i<=N; i++){
        B[i].first = A[i];
        B[i].second = i;
    }
    sort(B+1,B+N+1);
    for (int i=N; i>=1; i--){
        ubaci(B[i].second);
    }
    for (int i=N; i>=1; i--){
        L[i] = max(L[i],L[i+1]);
    }
    for (int i=1; i<=N; i++){
        printf("%d%c",L[i],i==N?'\n':' ');
    }
    return 0;
}