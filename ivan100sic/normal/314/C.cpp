#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define MAXN 1048576
#define OFFS 1048575
using namespace std;

struct node{
    int br,rmc;
    inline friend node operator +(node a,node b){
        b.br += a.br;
        if (b.br >= MOD) b.br -= MOD;
        return b;
    }
};

node Tree[2*MAXN];

void init(){
    int i;
    for (i=MAXN; i<2*MAXN; i++) Tree[i].rmc = i;
    for (i=OFFS; i>=1; i--) Tree[i] = Tree[2*i] + Tree[2*i+1];
}

node range(int l,int r){
    l+=OFFS;
    r+=OFFS;
    bool empty=true;
    node z;
    while (l<=r){
        while (l%2==0 && Tree[l/2].rmc <= r) l/=2;
        if (empty) z = Tree[l],empty=false; else z = z + Tree[l];
        l = Tree[l].rmc + 1;
    }
    return z;
}

void repair(int x){
    x+=OFFS;
    while (x>1){
        x/=2;
        Tree[x] = Tree[2*x] + Tree[2*x+1];
    }
}

int A[100005];
int N,i,j,k;
long long r;

int main(){
    init();
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
    for (i=1; i<=N; i++){
        r = range(1,A[i]).br + 1;
        Tree[A[i] + OFFS].br = (1ll * r * A[i]) % MOD;
        repair(A[i]);
    }
    r = 0;
    for (i=1; i<=1000000; i++) r += Tree[i+OFFS].br;
    printf("%lld\n",r%MOD);
    return 0;
}