#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define MASK(i) (1<<(i))
using namespace std;
int a[MASK(13)],high[MASK(13)],n;
long long f[MASK(13)];
void init(void) {
    scanf("%d",&n);
    FOR(i,2,MASK(n+1)-1) scanf("%d",&a[i]);
}
void dfs(int u) {
    if (u>=MASK(n)) return;
    dfs(2*u);
    dfs(2*u+1);
    high[u]=max(high[2*u]+a[2*u],high[2*u+1]+a[2*u+1]);
    f[u]=f[2*u]+f[2*u+1]+high[u]-high[2*u]-a[2*u]+high[u]-high[2*u+1]-a[2*u+1];
}
void process(void) {
    dfs(1);
    cout<<f[1]<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}