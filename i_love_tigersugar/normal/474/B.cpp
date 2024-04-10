#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int s[MAX];
int n;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void init(void) {
    n=nextInt();
    FOR(i,1,n) s[i]=s[i-1]+nextInt();
}
void process(void) {
    REP(zz,nextInt()) printf("%d\n",(int)(lower_bound(s+1,s+n+1,nextInt())-s));
}
int main(void) {
    init();
    process();
    return 0;
}