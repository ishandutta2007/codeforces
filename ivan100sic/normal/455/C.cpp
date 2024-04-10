#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int P1[300005],P2[300005],C[300005],PA[300005],O[600005];
int N,M,Qu;

void ucitajisredi(){
    int i,j;
    scanf("%d%d%d",&N,&M,&Qu);
    for (i=1; i<=M; i++){
        scanf("%d%d",P1+i,P2+i);
        C[P1[i]]++;
        C[P2[i]]++;
    }
    PA[1] = 1;
    for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
    memset(C,0,sizeof(C));
    for (i=1; i<=M; i++){
        O[PA[P1[i]]+C[P1[i]]] = P2[i];
        O[PA[P2[i]]+C[P2[i]]] = P1[i];
        C[P1[i]]++;
        C[P2[i]]++;
    }
}

int Q[300005],D[300005],Prev[300005],T[300005],qs,qe,vreme;

void bfs(int x0){
    int i,j;
    qs=qe=1;
    vreme++;

    Q[1] = x0;
    Prev[x0] = x0;
    D[x0] = 0;
    T[x0] = vreme;

    while (qs<=qe){
        x0 = Q[qs];
        qs++;
        for (i=PA[x0]; i<PA[x0+1]; i++){
            j = O[i];
            if (T[j]==vreme) continue;
            T[j] = vreme;
            Prev[j] = x0;
            D[j] = D[x0]+1;
            Q[++qe] = j;
        }
    }
}

int KompCentar[300005],KompRadijus[300005],KompDia[300005];

void resikomp(int x){
    int i,j,k,rad,cnt,dia;
    bfs(x);
    k = Q[qe];
    bfs(k);
    cnt = Q[qe];
    dia = D[cnt];
    rad = (dia+1)/2;
    for (i=1; i<=rad; i++) cnt = Prev[cnt];
    for (i=1; i<=qe; i++){
        KompCentar[Q[i]] = cnt;
        KompRadijus[Q[i]] = rad;
        KompDia[Q[i]] = dia;
    }
}

//DSU

int Parent[300005];

int findparent(int x){
    if (Parent[x] == x) return x;
    return Parent[x] = findparent(Parent[x]);
}

void setparent(){
    int i;
    for (i=1; i<=N; i++) Parent[i] = KompCentar[i];
}

void spoji(int a,int b){
    int ax,bx,nl,nd;
    ax = findparent(a);
    bx = findparent(b);
    if (ax==bx) return;
    //spajanje!

    nd = max(max(KompDia[ax],KompDia[bx]),KompRadijus[ax]+KompRadijus[bx]+1);
    nl = (nd + 1) / 2;

    //printf("%d %d : %d %d\n",a,b,nd,nl);

    if (KompRadijus[ax] < KompRadijus[bx]){
        Parent[ax] = bx;
        KompRadijus[bx] = nl;
        KompDia[bx] = nd;
    } else {
        Parent[bx] = ax;
        KompRadijus[ax] = nl;
        KompDia[ax] = nd;
    }
}

int odgovori(int x){
    return KompDia[findparent(x)];
}

int main(){
    ucitajisredi();
    int i;
    for (i=1; i<=N; i++) if (KompCentar[i]==0) resikomp(i);
    setparent();

    //for (i=1; i<=N; i++) printf("%d: %d %d %d\n",i,KompCentar[i],KompRadijus[i],KompDia[i]);

    int t,x,y;
    while (Qu--){
        scanf("%d",&t);
        if (t==1){
            scanf("%d",&x);
            printf("%d\n",odgovori(x));
        } else {
            scanf("%d%d",&x,&y);
            spoji(x,y);
        }
    }
    return 0;
}