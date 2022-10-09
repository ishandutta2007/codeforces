#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1048576
#define OFFS 1048575
using namespace std;

int P1[500005],P2[500005],C[500005],O[1000005],PA[500005],N;

void ucitajisredi(){
    int i;
    scanf("%d",&N);
    for (i=1; i<N; i++){
        scanf("%d%d",P1+i,P2+i);
        C[P1[i]]++;
        C[P2[i]]++;
    }
    PA[1] = 1;
    for (i=2; i<=N+1; i++) PA[i] = PA[i-1] + C[i-1];
    memset(C,0,sizeof(C));
    for (i=1; i<N; i++){
        O[PA[P1[i]]+C[P1[i]]] = P2[i];
        O[PA[P2[i]]+C[P2[i]]] = P1[i];
        C[P1[i]]++;
        C[P2[i]]++;
    }
}

int L[500005],R[500005],vreme;

void dfs(int x,int odakle){
    int i,y;
    vreme++;
    L[x] = vreme;
    for (i=PA[x]; i<PA[x+1]; i++) if (O[i]!=odakle) dfs(O[i],x);
    vreme++;
    R[x] = vreme;
}

int EmptyTree[2*MAXN],FillTree[2*MAXN],RMC[2*MAXN];
int Tip[500005];

void isprazni(int x){
    vreme++;
    x = L[x]+OFFS;
    while (x>0){
        EmptyTree[x] = vreme;
        //printf("e set %d -> %d\n",x,vreme);
        x/=2;
    }
}

void rmcuj(){
    int i;
    for (i=MAXN; i<2*MAXN; i++) RMC[i] = i;
    for (i=OFFS; i>=1; i--) RMC[i] = RMC[2*i+1];
}

void napuni(int x){
    int l,r;
    vreme++;
    Tip[vreme] = 1;
    l = L[x] + OFFS;
    r = R[x] + OFFS;
    while (l<=r){
        while (l%2==0 && RMC[l/2] <= r) l/=2;
        FillTree[l] = vreme;
        l = RMC[l]+1;
    }
}

int nadjivreme(int x){
    //rastavimo x na delove i gledamo ih u EmptyTree
    int l,r,res=0;
    l = L[x] + OFFS;
    r = R[x] + OFFS;
    //printf("%d %d\n",l,r);
    while (l<=r){
        while (l%2 == 0 && RMC[l/2] <= r) l/=2;
        res = max(res , EmptyTree[l]);
        //printf("e read %d -> %d\n",l,EmptyTree[l]);
        l = RMC[l]+1;
    }
    //pa se prosetamo na gore u FillTree
    x = L[x] + OFFS;
    while (x>0){
        res = max(res , FillTree[x]);
        x/=2;
    }
    return res;
}

void odgovori(){
    int tip,x;
    scanf("%d%d",&tip,&x);
    if (tip==1){
        napuni(x);
    } else
    if (tip==2){
        isprazni(x);
    } else {
        tip = nadjivreme(x);
        //printf("vreme = %d odgovor = %d\n",tip,Tip[tip]);
        printf("%d\n",Tip[tip]);
    }
}

int main(){
    ucitajisredi();
    dfs(1,1);
    rmcuj();
    //for (int i=1; i<=N; i++) printf("%d : %d %d\n",i,L[i],R[i]);
    int Q;
    scanf("%d",&Q);
    vreme = 0;
    while (Q--) odgovori();
    return 0;
}