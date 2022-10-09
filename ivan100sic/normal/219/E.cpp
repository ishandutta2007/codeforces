#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 262144
#define OFFS 262143
using namespace std;

int Tree[2*MAXN];
int RF[MAXN],Pos[1000001],C[MAXN],N,M;

void dodaj(int p,int v){
    while (p<MAXN){
        C[p]+=v;
        p+=p&(-p);
    }
}

int citaj(int p){
    int r=0;
    while (p){
        r+=C[p];
        p-=p&(-p);
    }
    return r;
}

int realdist(int x){
    if (RF[x]==0) return -1;
    if (x==1) return RF[x]-1;
    if (citaj(x)==citaj(N+1)) return RF[x]-1;
    return (RF[x]-1)/2;
}

int realpos(int x){
    if (x==1) return 2;
    if (citaj(x)==citaj(N+1)) return N+1; else
    return x+(RF[x]+1)/2;
}

int boljicvor(int a,int b){
    int aa,bb;
    aa = realdist(a);
    bb = realdist(b);
    if (aa > bb || (aa==bb && a<b)) return a; else return b;
}

void initstablo(){
    for (int i=1; i<=N+1; i++) Tree[i+OFFS] = i;
}

void update(int x){
    x+=OFFS;
    while (x>1){
        x/=2;
        Tree[x] = boljicvor(Tree[2*x],Tree[2*x+1]);
    }
}

void ubaciauto(int id){
    int i,j,k;
    k = Tree[1];
    j = realpos(k);
    RF[j] = RF[k]-j+k;
    RF[k] = j-k-1;
    Pos[id] = j;
    dodaj(j,1);
    update(k);
    update(j);
    //for (i=1; i<=N+1; i++) printf("%d ",RF[i]);
    //puts("");
    printf("%d\n",j-1);
}

void izbaciauto(int id){
    int i,j,k,l,r,m,o;
    j = Pos[id];
    l=1;
    r=N+1;
    while (l<=r){
        m = (l+r)/2;
        if (citaj(m) >= citaj(j-1)){
            o = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    k=o;
    dodaj(j,-1);
    //printf("end %d %d\n",k,j);
    RF[k] += RF[j]+1;
    RF[j] = 0;
    //for (i=1; i<=N+1; i++) printf("%d ",RF[i]);
    //puts("");
    update(k);
    update(j);
}

int a,b;

int main(){
    scanf("%d%d",&N,&M);
    initstablo();
    dodaj(1,1);
    RF[1] = N;
    update(1);
    while (M--){
        scanf("%d%d",&a,&b);
        if (a==1) ubaciauto(b); else izbaciauto(b);
    }
    return 0;
}