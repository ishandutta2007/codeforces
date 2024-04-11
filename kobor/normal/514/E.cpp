//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int mod=1e9+7;
const int N=101;

typedef long long mat[N+1][N+1];

mat base, ret, pom;

void mnoz(mat &m0, mat &m1, mat &m2){
	FOR(i, 1, N) FOR(j, 1, N) m0[i][j]=0;
	// memset(m0, 0, sizeof(m0));
	FOR(i, 1, N) FOR(k, 1, N) FOR(j, 1, N) m0[i][j]=(m0[i][j]+(ll)m1[i][k]*m2[k][j])%mod;
}

void ustaw(mat &m0, mat &m1){
	FOR(i, 1, N) FOR(j, 1, N) m0[i][j]=m1[i][j];
	// memcpy(m0, m1, sizeof(m0));
}

void pov(int exp){
	FOR(i, 1, N) ret[i][i]=1;
	while(exp){
		if(exp&1) mnoz(pom, ret, base), ustaw(ret, pom);
		mnoz(pom, base, base), ustaw(base, pom);
		exp>>=1;
	}
}

void solve(){
	int n, k, a;
	cin>>n>>k;
	FOR(i, 1, n){
		cin>>a;
		base[1][a]++;
	}
	FOR(i, 2, N-1) base[i][i-1]++;
	base[N][1]=base[N][N]=1;
	pov(k+1);
	cout<<ret[N][1]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}