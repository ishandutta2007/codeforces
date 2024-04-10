#include<bits/stdc++.h>
#define MAX   50050
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
long long f[MAX][7];
int t[MAX][7];
int m,n;
void process(void) {
    scanf("%d%d",&m,&n);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&t[i][j]);
    FOR(i,1,m) FOR(j,1,n) f[i][j]=max(f[i-1][j],f[i][j-1])+t[i][j];
    FOR(i,1,m) {
        cout << f[i][n];
        if (i<m) cout << " ";
    }
}
int main(void) {
    process();
    return 0;
}