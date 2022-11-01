#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

using namespace std;

int n, m;
int f[100005];
int b[100005];
int a[100005];

map < int, vector < int > > M;

int main(){
	cin >> n >> m;
	REP(i,n) scanf("%d", f+i), M[f[i]].pb(i);
	REP(i,m) scanf("%d", b+i);
	
	REP(i,m) if (M[b[i]].empty()){
		cout << "Impossible\n";
		return 0;
	}
	
	REP(i,m) if (M[b[i]].size() != 1){
		cout << "Ambiguity\n";
		return 0;
	}
	
	cout << "Possible" << endl;
	REP(i,m) a[i] = M[b[i]][0]+1;
	REP(i,m) printf("%d ", a[i]); cout << endl;
	
	return 0;
}