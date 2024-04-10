#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define vf vector<funk>
#define vs vector<seg>
#define MAXN 131072
#define OFFS 131071
using namespace std;

struct funk{
    long long k,b;
    inline friend bool operator <(funk a,funk b){
        return a.k < b.k || (a.k == b.k && a.b > b.b);
    }
};

struct seg{
    long long b,k;
    double st;
};

void merge(vf &a,vf &b,vf &c){
    int n,m,i,j,k,br;
    n = a.size();
    m = b.size();
    c.resize(n+m);
    i=j=k=0;
    while (k<n+m){
        if (i==n){
            br=2;
        } else
        if (j==m){
            br=1;
        } else {
            br = a[i]<b[j]?1:2;
        }
        if (br==1){
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
}

struct cvor{
    vf F;
    vs S;
    int rmc;
};

int A[100005],Z[100005],N;

void ucitaj(){
    int i;
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d",A+i);
}

cvor Tree[2*MAXN];
seg St[MAXN];
int ss;

double intersect(funk u,seg v){
    return ((double)u.b - v.b) / (v.k - u.k);
}

void konveks(vf &F,vs &S){
    int i,j,n;
    n = F.size();
    double x;
    ss=1;
    St[1].st = -2e10;
    St[1].b = F[n-1].b;
    St[1].k = F[n-1].k;
    for (i=n-2; i>=0; i--){
        //printf("%d\n",i);
        if (F[i].k == F[i+1].k) continue;
        while (true){
            x = intersect(F[i],St[ss]);
            if (x < St[ss].st) ss--; else break;
        }
        ss++;
        St[ss].b = F[i].b;
        St[ss].k = F[i].k;
        St[ss].st = x;
    }
    S.resize(ss);
    for (i=1; i<=ss; i++) S[i-1] = St[i];
    F.clear();
}

funk nadji(vs &S,double x){
    funk re;
    int l,r,m,o;
    l = 0;
    r = S.size()-1;
    while (l<=r){
        m = (l+r)/2;
        if (S[m].st <= x){
            o = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    re.k = S[o].k;
    re.b = S[o].b;
    return re;
}

void napravi(){
    int i;
    for (i=N; i>=1; i--) Z[i] = Z[i+1] + A[i];
    //for (i=1; i<=N; i++) Z[i] += i*A[i];
    //najgori deo ikad
    for (i=MAXN; i<2*MAXN; i++){
        Tree[i].F.resize(1);
        Tree[i].rmc = i;
    }
    for (i=1; i<=N; i++){
        Tree[i+OFFS].F[0].b = Z[i] + i*A[i];
        Tree[i+OFFS].F[0].k = A[i];
    }
    for (i=OFFS; i>=1; i--){
        Tree[i].rmc = Tree[2*i+1].rmc;
        merge(Tree[2*i].F,Tree[2*i+1].F,Tree[i].F);
    }
    for (i=1; i<2*MAXN; i++) konveks(Tree[i].F,Tree[i].S);
    //printf("ok\n");
}

void debag(int x){
    int i,n;
    n = Tree[x].S.size();
    for (i=0; i<n; i++) printf("%.9lf %lld %lld\n",Tree[x].S[i].st,Tree[x].S[i].b,Tree[x].S[i].k);
}

int odgovori(int l,int r){
    int il,ir,ans=1000000009;
    funk p;
    il = l+OFFS;
    ir = r+OFFS;
    int vred;
    while (il<=ir){
        while (il%2==0 && Tree[il/2].rmc <= ir) il/=2;
        vred = -l; //nesto
        p = nadji(Tree[il].S,vred);
        //printf("%lld %lld %d %d\n",p.b,p.k,Z[r+1],l);
        ans = min(ans , (int)(p.k*vred + p.b - Z[r+1]));
        il = Tree[il].rmc + 1;
    }
    return ans;
}

int main(){
    ucitaj();
    napravi();

    //debag((6+OFFS)/2);

    int q,x,y;
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&x,&y);
        printf("%d\n",odgovori(y-x+1,y));
    }
    return 0;
}