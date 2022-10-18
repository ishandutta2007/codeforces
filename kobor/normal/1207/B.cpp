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

const int N=55;

int n, m;
bool mat[N][N], haha[N][N];
int yy[4]={-1, -1, 0, 0}, xx[4]={-1, 0, -1, 0};
vii ans;

bool moge(int a, int b){
	return mat[a][b] && mat[a+1][b] && mat[a][b+1] && mat[a+1][b+1];
}

void solve(){
	cin>>n>>m;
	FOR(i, 1, n) FOR(j, 1, m) cin>>mat[i][j];
	FOR(i, 1, n) FOR(j, 1, m){
		if(!mat[i][j]) continue;
		bool git=0;
		FOR(k, 0, 3){
			if(moge(i+yy[k], j+xx[k])){
				git=1;
				ans.pb({i+yy[k], j+xx[k]});
				break;
			}
		}
		if(!git){
			cout<<-1<<ent;
			return;
		}
	}
	cout<<SIZE(ans)<<ent;
	for(auto &x: ans) cout<<x.st<<sp<<x.nd<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}