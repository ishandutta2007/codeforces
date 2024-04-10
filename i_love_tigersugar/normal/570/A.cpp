#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
using namespace std;
long long a[MAX][MAX];
int m,n,win[MAX];
void init(void) {
    cin>>n>>m;
    FOR(i,1,m) FOR(j,1,n) cin>>a[i][j];
}
int winner(int i) {
    int res=1;
    FOR(j,1,n) if (a[i][j]>a[i][res]) res=j;
    return (res);
}
void process(void) {
    FOR(i,1,m) win[winner(i)]++;
    int res=1;
    FOR(j,1,n) if (win[j]>win[res]) res=j;
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}