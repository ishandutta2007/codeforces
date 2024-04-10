#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 524288
#define OFFS 524287
using namespace std;

struct upit{
    int tip,n1,n2;
};

int A0[100005],A[100005],N,KP,Q;
int B[300005];
upit U[100005];

void ucitaj(){
    scanf("%d",&N);
    int i;
    for (i=1; i<=N; i++) scanf("%d",A0+i);
    scanf("%d",&Q);
    for (i=1; i<=Q; i++){
        scanf("%d%d%d",&U[i].tip,&U[i].n1,&U[i].n2);
    }
}

void sredi_koord(){
    int i,j,k;
    memcpy(A,A0,sizeof(A));
    for (i=1; i<=N; i++) B[i] = A0[i];
    j=N;
    for (i=1; i<=Q; i++){
        if (U[i].tip == 1){
            j++;
            A[U[i].n1] += U[i].n2;
            B[j] = A[U[i].n1];
        } else {
            j++;
            B[j] = U[i].n1;
            j++;
            B[j] = U[i].n2;
        }
    }
    k=j;
    sort(B+1,B+k+1);
    j=1;
    for (i=2; i<=k; i++){
        if (B[i] != B[i-1]){
            j++;
            B[j] = B[i];
            //printf("%d\n",B[j]);
        }
    }
    KP=j;
}

struct cvor{
    int lx,rx,br,rmc;
    long long sumx,sumd;
    friend cvor operator + (cvor a,cvor b){
        cvor t;
        t.lx = a.lx;
        t.rx = b.rx;
        t.br = a.br + b.br;
        t.rmc = b.rmc;
        t.sumx = a.sumx + b.sumx;
        t.sumd = a.sumd + b.sumd - a.sumx*b.br + b.sumx*a.br;
        return t;
    }
};

cvor Tree[2*MAXN];

int cvor_koord(int x){
    int l,r,m;
    l=1;
    r=KP;
    while (l<=r){
        m = (l+r)/2;
        if (B[m] < x){
            l = m+1;
        } else
        if (B[m] > x){
            r = m-1;
        } else return m+OFFS;
    }
    printf("fuck you\n");
    return -1;
}

void ubaci_tacku(int pos,int znak){
    int idx = cvor_koord(pos);
    Tree[idx].br += znak;
    Tree[idx].sumx += znak * pos;
    while (idx>1){
        idx /= 2;
        Tree[idx] = Tree[2*idx] + Tree[2*idx+1];
    }
}

void init_tree(){
    int i;
    for (i=1; i<=KP; i++){
        Tree[i+OFFS].lx = B[i];
        Tree[i+OFFS].rx = B[i];
        Tree[i+OFFS].rmc = i+OFFS;
    }
    for (i=KP+1; i<=MAXN; i++){
        Tree[i+OFFS].lx = 2000000000;
        Tree[i+OFFS].rx = 2000000000;
        Tree[i+OFFS].rmc = i+OFFS;
    }
    //ubaci tacke sa pocetka
    for (i=1; i<=N; i++) ubaci_tacku(A0[i],+1);
    for (i=OFFS; i>=1; i--){
        Tree[i] = Tree[2*i] + Tree[2*i+1];
    }
}

void resi(){
    int i,j,k,l,r;
    bool empty;
    cvor jt;
    memcpy(A,A0,sizeof(A));
    for (i=1; i<=Q; i++){
        if (U[i].tip == 1){
            ubaci_tacku(A[U[i].n1],-1);
            A[U[i].n1] += U[i].n2;
            ubaci_tacku(A[U[i].n1],+1);
        } else {
            l = cvor_koord(U[i].n1);
            r = cvor_koord(U[i].n2);
            empty=true;
            while (l<=r){
                while (l%2==0 && Tree[l/2].rmc <= r) l/=2;
                if (empty){
                    empty = false;
                    jt = Tree[l];
                } else {
                    jt = jt + Tree[l];
                }
                l = Tree[l].rmc + 1;
            }
            printf("%I64d\n",jt.sumd);
        }
    }
}

int main(){
    ucitaj();
    sredi_koord();
    init_tree();
    resi();
    return 0;
}