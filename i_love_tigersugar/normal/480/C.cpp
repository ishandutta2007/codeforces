#include<bits/stdc++.h>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
inline void add(int &x,const int &y) {
    x+=y;
    if (x>=mod) x-=mod;
}
inline void sub(int &x,const int &y) {
    x-=y;
    if (x<0) x+=mod;
}
inline int Abs(int x) {
    return (x<0?-x:x);
}
int f[MAX][MAX],s[MAX][MAX];
int n,a,b,k;
void process(void) {
    scanf("%d%d%d%d",&n,&a,&b,&k);
    FOR(i,1,n) f[i][0]=(i!=b);
    FOR(i,1,n) {
        s[i][0]=s[i-1][0];
        add(s[i][0],f[i][0]);
    }
    FOR(j,1,k) FOR(i,1,n) {
        if (i==b) f[i][j]=0;
        else {
            int c=Abs(i-b);
            f[i][j]=s[min(i+c-1,n)][j-1];
            if (i-c+1>=1) sub(f[i][j],s[i-c][j-1]);
            sub(f[i][j],f[i][j-1]);
        }
        s[i][j]=s[i-1][j];
        add(s[i][j],f[i][j]);
    }
    printf("%d",f[a][k]);
}
int main(void) {
    process();
    return 0;
}