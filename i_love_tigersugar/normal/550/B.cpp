#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
const int INF=(int)1e9+7;
int n,l,r,x,a[33];
void init(void) {
    scanf("%d%d%d%d",&n,&l,&r,&x);
    REP(i,n) scanf("%d",&a[i]);
}
bool ok(int mask) {
    if (__builtin_popcount(mask)<2) return (false);
    int minVal=INF;
    int maxVal=-INF;
    int sum=0;
    REP(i,n) if (BIT(mask,i)) {
        minVal=min(minVal,a[i]);
        maxVal=max(maxVal,a[i]);
        sum+=a[i];
    }
    return (l<=sum && sum<=r && maxVal-minVal>=x);
}
void process(void) {
    int res=0;
    REP(i,MASK(n)) if (ok(i)) res++;
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}