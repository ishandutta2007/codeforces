#include<bits/stdc++.h>
#define MAX   5050
#define MAXV   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int INF=(int)1e9+7;
vector<int> prime;
bool notprime[MAXV];
int a[MAX],b[MAX],gc[MAX],gf[MAX],f[MAX];
int n,m;
int gcd(int a,int b) {
    if (a<0) a=-a;
    if (b<0) b=-b;
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a=a%b; else b=b%a;
    }
}
void eratosthene(void) {
    REP(j,2) notprime[j]=true;
    FOR(i,2,MAXV-1) if (!notprime[i]) {
        prime.push_back(i);
        for (int j=2*i;j<MAXV;j=j+i) notprime[j]=true;
    }
}
bool find(int x) {
    if (x==0) return (false);
    int id=lower_bound(b+1,b+m+1,x)-b;
    return (b[id]==x);
}
int func(int x) {
    int ret=0;
    FORE(it,prime) {
        if (1LL*(*it)*(*it)>x) break;
        if (x%*it==0) {
            int add=find(*it)?-1:1;
            while (x%*it==0) {
                ret+=add;
                x=x/(*it);
            }
        }
    }
    if (x>1) {
        if (find(x)) ret--; else ret++;
    }
    return (ret);
}
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,m) scanf("%d",&b[i]);
    //FOR(i,1,n) printf("%d ",a[i]); printf("\n");
    sort(b+1,b+m+1);
    FOR(i,1,n) {
        gc[i]=(i>1)?gcd(gc[i-1],a[i]):a[i];
        if (i>1) {
            if (gc[i]==gc[i-1]) gf[i]=gf[i-1];
            else {
                if (gc[i-1]/gc[i]>gc[i]) gf[i]=func(gc[i]);
                else gf[i]=gf[i-1]-func(gc[i-1]/gc[i]);
            }
        }
        else gf[i]=func(gc[i]);
    }
    //FOR(i,1,n) printf("%d ",gc[i]); printf("\n");
    //FOR(i,1,n) printf("%d ",gf[i]); printf("\n");
}
void optimize(void) {
    FOR(i,1,n) f[n+1]+=func(a[i]);
    FORD(i,n,1) {
        f[i]=f[n+1]-i*gf[i];
        FOR(j,i+1,n) maximize(f[i],f[j]-i*(gf[i]-gf[j]));
    }
    int res=-INF;
    FOR(i,1,n+1) maximize(res,f[i]);
    printf("%d",res);
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    eratosthene();
    init();
    optimize();
    return 0;
}