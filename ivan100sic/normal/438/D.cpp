#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 131072
#define OFFS 131071
using namespace std;

int A[MAXN],N,M;
int MaxTree[2*MAXN],RMC[2*MAXN];
long long SumTree[2*MAXN];

int bolji(int a,int b){
    if (A[a] > A[b]) return a; else return b;
}

void ucitaj(){
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++){
        scanf("%d",A+i);
        SumTree[i+OFFS] = A[i];
    }
    for (i=1; i<=MAXN; i++){
        MaxTree[i+OFFS] = i;
        RMC[i+OFFS] = i+OFFS;
    }
    for (i=OFFS; i>=1; i--){
        MaxTree[i] = bolji(MaxTree[2*i],MaxTree[2*i+1]);
        SumTree[i] = SumTree[2*i] + SumTree[2*i+1];
        RMC[i] = RMC[2*i+1];
    }
}

int lpre,rpre;
int Nd[100],nc;

void getnodes(int l,int r){
    if (l==lpre && r==rpre) return;
    lpre = l;
    rpre = r;
    nc = 0;
    l += OFFS;
    r += OFFS;
    while (l<=r){
        while (l%2 == 0 && RMC[l/2] <= r) l/=2;
        nc++;
        Nd[nc] = l;
        l = RMC[l]+1;
    }
}

int getmax(int l,int r){
    getnodes(l,r);
    int x = MaxTree[Nd[1]];
    for (int i=2; i<=nc; i++) x = bolji(x , MaxTree[Nd[i]]);
    return x;
}

void upisi(int x,int vr){
    A[x] = vr;
    x += OFFS;
    SumTree[x] = vr;
    while (x>1){
        x /= 2;
        SumTree[x] = SumTree[2*x] + SumTree[2*x+1];
        MaxTree[x] = bolji(MaxTree[2*x],MaxTree[2*x+1]);
    }
}

void reduce_mod(int l,int r,int mod){
    int mx,mv;
    while (true){
        mx = getmax(l,r);
        mv = A[mx];
        if (mv < mod) return;
        upisi(mx,mv % mod);
    }
}

long long sumq(int l,int r){
    getnodes(l,r);
    long long z=0;
    for (int i=1; i<=nc; i++) z += SumTree[Nd[i]];
    return z;
}

int main(){
    ucitaj();
    int t,l,r,x;
    while (M--){
        scanf("%d",&t);
        if (t==1){
            scanf("%d%d",&l,&r);
            printf("%lld\n",sumq(l,r));
        } else
        if (t==2){
            scanf("%d%d%d",&l,&r,&x);
            reduce_mod(l,r,x);
        } else {
            scanf("%d%d",&l,&x);
            upisi(l,x);
        }
    }
    return 0;
}