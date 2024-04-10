#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 131072
#define OFFS 131071
using namespace std;

struct cvor{
    int farba,vreme,rmc;
};

cvor Tree[2*MAXN];

int tm;

void farbaj(int l,int r,int boja){
    tm++;
    l+=OFFS;
    r+=OFFS;
    while (l<=r){
        while (l%2==0 && Tree[l/2].rmc <= r) l/=2;
        Tree[l].farba = boja;
        Tree[l].vreme = tm;
        l = Tree[l].rmc+1;
    }
}

int nadji_boju_i_vreme(int x,int &boja,int &vreme){
    x += OFFS;
    boja=0;
    vreme=0;
    while (x>0){
        if (Tree[x].vreme > vreme){
            boja = Tree[x].farba;
            vreme = Tree[x].vreme;
        }
        x/=2;
    }
    return boja;
}

int A[100005],B[100005],N,Q,i,j,k,l;

int main(){
    scanf("%d%d",&N,&Q);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=1; i<=N; i++) scanf("%d",B+i);
    for (i=MAXN; i<2*MAXN; i++) Tree[i].rmc = i;
    for (i=OFFS; i>=1; i--) Tree[i].rmc = Tree[2*i+1].rmc;
    while (Q--){
        scanf("%d",&i);
        if (i==2){
            scanf("%d",&j);
            nadji_boju_i_vreme(j,k,l);
            if (l==0) printf("%d\n",B[j]); else printf("%d\n",A[j+k]);
        } else {
            scanf("%d%d%d",&j,&k,&l);
            farbaj(k,k+l-1,j-k);
        }
    }
    return 0;
}