#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int defMod=(int)2e9+2277;
const char yes[]="YES";
const char no[]="NO";
int a[MAX],b[MAX],c[MAX][MAX];
int m,n,mod;
int gcd(int a,int b) {
    if (a<0) a=-a;
    if (b<0) b=-b;
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
void init(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&c[i][j]);
}
void noAnswer(void) {
    printf("%s\n",no);
    exit(0);
}
int getDiffA(int i,int j) {
    set<int> s;
    FOR(k,1,n) s.insert(c[i][k]-c[j][k]);
    if (s.size()==1) return (-1);
    if (s.size()>=3) noAnswer();
    if (*s.begin()>=0 || *s.rbegin()<0) noAnswer();
    return (*s.rbegin()-*s.begin());
}
int getDiffB(int i,int j) {
    set<int> s;
    FOR(k,1,m) s.insert(c[k][i]-c[k][j]);
    if (s.size()==1) return (-1);
    if (s.size()>=3) noAnswer();
    if (*s.begin()>=0 || *s.rbegin()<0) noAnswer();
    return (*s.rbegin()-*s.begin());
}
void process(void) {
    mod=-1;
    FOR(i,1,m) FOR(j,i+1,m) {
        int v=getDiffA(i,j);
        if (v<0) continue;
        if (mod<0) mod=v;
        else if (mod!=v) noAnswer();
    }
    FOR(i,1,n) FOR(j,i+1,n) {
        int v=getDiffB(i,j);
        if (v<0) continue;
        if (mod<0) mod=v;
        else if (mod!=v) noAnswer();
    }
    if (mod<=0) mod=defMod;
    FOR(i,1,m) FOR(j,1,n) if (c[i][j]>=mod) noAnswer();
    a[1]=0;b[1]=c[1][1];
    FOR(i,2,m) a[i]=((0LL+a[1]+c[i][1]-c[1][1])%mod+mod)%mod;
    FOR(i,2,n) b[i]=((0LL+b[1]+c[1][i]-c[1][1])%mod+mod)%mod;
    FOR(i,1,m) FOR(j,1,n) if ((0LL+a[i]+b[j])%mod!=c[i][j]) noAnswer();
    FOR(i,1,m) assert(0<=a[i] && a[i]<mod);
    FOR(i,1,n) assert(0<=b[i] && b[i]<mod);
    printf("%s\n",yes);
    printf("%d\n",mod);
    FOR(i,1,m) printf("%d ",a[i]); printf("\n");
    FOR(i,1,n) printf("%d ",b[i]); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}