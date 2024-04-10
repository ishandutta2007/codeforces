#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
ll t[5][5];
ll f[55][5][5];
int n;
void minimize(ll &x,const ll &y) {
	if (x>y) x=y;
}
void process(void) {
	REP(i,3) REP(j,3) cin >> t[i][j];
	cin >> n;
	REP(i,3) REP(j,3) if (i!=j) f[1][i][j]=min(t[i][j],t[i][3-i-j]+t[3-i-j][j]);
	//REP(i,3) REP(j,3) if (i!=j) printf("F %d %d %d = %d\n",1,i,j,f[1][i][j]);
	FOR(i,2,n) REP(j,3) REP(k,3) if (j!=k) {
		int l=3-j-k;
		f[i][j][k]=INF;
		minimize(f[i][j][k],f[i-1][j][l]+t[j][k]+f[i-1][l][k]);
		minimize(f[i][j][k],f[i-1][j][k]+t[j][l]+f[i-1][k][j]+t[l][k]+f[i-1][j][k]);
	//	printf("F %d %d %d = %d\n",i,j,k,f[i][j][k]);
	}
	cout << f[n][0][2];
}
int main(void) {
	process();
	return 0;
}