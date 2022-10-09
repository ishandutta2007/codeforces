#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;

struct dsu{
    int P[505],Sz[505],komp;

    void init(){
        for (int i=1; i<=N; i++){
            P[i] = i;
            Sz[i] = i;
        }
        komp = N;
    }

    int endparent(int x){
        while (x!=P[x]) x=P[x];
        return x;
    }

    bool spoji(int a,int b){
        a = endparent(a);
        b = endparent(b);
        if (a==b) return false;
        if (Sz[a] < Sz[b]){
            P[a] = b;
            Sz[b] += Sz[a];
        } else {
            P[b] = a;
            Sz[a] += Sz[b];
        }
        komp--;
        return true;
    }
};

int P1[10005],P2[10005];
bool LeftUseful[10005],RightUseful[10005];
int PrviLevoKoristan[10005],PrviDesnoKoristan[10005];
int P1lu[505],P2lu[505],M;
int P1ru[505],P2ru[505];
int Sol[505][505];

dsu samolevo,cepanje;

void ucitaj(){
    scanf("%d%d",&N,&M);
    for (int i=1; i<=M; i++){
        scanf("%d%d",P1+i,P2+i);
    }
}

void nadji_korisne(){
    int i,j;
    cepanje.init();
    for (i=1; i<=M; i++){
        if (cepanje.spoji(P1[i],P2[i])){
            LeftUseful[i] = true;
        }
    }
    cepanje.init();
    for (i=M; i>=1; i--){
        if (cepanje.spoji(P1[i],P2[i])){
            RightUseful[i] = true;
        }
    }
    j=0;
    for (i=1; i<=M; i++){
        if (LeftUseful[i]){
            j++;
            P1lu[j] = P1[i];
            P2lu[j] = P2[i];
        }
        PrviLevoKoristan[i] = j;
    }
    j=0;
    for (i=M; i>=1; i--){
        if (RightUseful[i]){
            j++;
            P1ru[j] = P1[i];
            P2ru[j] = P2[i];
        }
        PrviDesnoKoristan[i] = j;
    }
}

void napravi_sol(){
    samolevo.init();
    int i,j;
    for (i=0; i<N; i++){
        if (i>0) samolevo.spoji(P1lu[i],P2lu[i]);
        cepanje = samolevo;
        for (j=0; j<N; j++){
            if (j>0) cepanje.spoji(P1ru[j],P2ru[j]);
            Sol[i][j] = cepanje.komp;
        }
    }
}

void resi(){
    int i,j,Q,l,r;
    scanf("%d",&Q);
    while (Q--){
        scanf("%d%d",&l,&r);
        l--;
        r++;
        printf("%d\n",Sol[PrviLevoKoristan[l]][PrviDesnoKoristan[r]]);
        //printf("%d (%d %d)\n",Sol[PrviLevoKoristan[l]][PrviDesnoKoristan[r]],PrviLevoKoristan[l],PrviDesnoKoristan[r]);
    }
}

int main(){
    ucitaj();
    nadji_korisne();
    napravi_sol();
    resi();
    return 0;
}