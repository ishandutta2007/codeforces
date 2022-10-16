#include<algorithm>
#include<cstdio>
#include<iostream>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
ll sa[MAX],sb[MAX];
int a[MAX],b[MAX];
int n;
inline int nextInt(void) {
    int x;
    scanf("%d",&x);
    return (x);
}
void init(void) {
    n=nextInt();
    FOR(i,1,n) a[i]=b[i]=nextInt();
    sort(b+1,b+n+1);
    FOR(i,1,n) {
        sa[i]=sa[i-1]+a[i];
        sb[i]=sb[i-1]+b[i];
    }
}
void process(void) {
    REP(zz,nextInt()) {
        int t=nextInt();
        int l=nextInt();
        int r=nextInt();
        if (t==1) cout<<sa[r]-sa[l-1]<<"\n"; else cout<<sb[r]-sb[l-1]<<"\n";
    }
    //REP(zz,nextInt()) cout<<(nextInt()==1?-sa[nextInt()-1]+sa[nextInt()]:-sb[nextInt()-1]+sb[nextInt()])<<"\n";
}
int main(void) {
    init();
    process();
    return 0;
}