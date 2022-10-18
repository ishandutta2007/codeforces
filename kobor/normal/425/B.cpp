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

const int N=105;

int n, m, k, lans, ans=inf;
int t[N][N], t2[N][N];

int func(){
	int ret=0, how;
	FOR(j, 2, m){
		how=0;
		FOR(i, 1, n) how+=(t[i][j]==t[i][1]);
		ret+=min(how, n-how);
	}
	return ret;
}

void solve(){
	cin>>n>>m>>k;
	FOR(i, 1, n) FOR(j, 1, m) cin>>t[i][j];
	if(n<=k){
		FOR(msk, 0, (1<<n)-1){
			FOR(i, 1, n) t[i][1]^=(msk&(1<<(i-1)))>>(i-1);
			ans=min(ans, __builtin_popcount(msk)+func());
			FOR(i, 1, n) t[i][1]^=(msk&(1<<(i-1)))>>(i-1);
		}
	}
	else{
		memcpy(t2, t, sizeof(t2));
		FOR(i, 1, n) FOR(j, 1, m) t[j][i]=t2[i][j];
		swap(n, m);
		ans=min(ans, func());
		FOR(j, 2, m){
			FOR(i, 1, n) swap(t[i][1], t[i][j]);
			ans=min(ans, func());
			FOR(i, 1, n) swap(t[i][1], t[i][j]);
		}
	}
	if(ans>k) ans=-1;
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}