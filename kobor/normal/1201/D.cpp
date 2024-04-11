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

const int N=2e5+5;

int lft[N], rght[N];
ll dp[N][2];
bool ciek[N];
int n, m, poprz=1;
vi cols={-inf, inf};

int dist(int prea, int preb, int akta, int aktb){
	int lewa, prawa;
	prawa=lewa=lower_bound(cols.begin(), cols.end(), preb)-cols.begin();
	lewa=cols[lewa-1];
	prawa=cols[prawa];
	return min(abs(preb-lewa)+abs(aktb-lewa), abs(preb-prawa)+abs(aktb-prawa))+akta-prea;
}

void solve(){
	memset(lft, inf, sizeof(lft));
	int a, b, k, q;
	cin>>n>>m>>k>>q;
	FOR(i, 1, k){
		cin>>a>>b;
		ciek[a]=1;
		lft[a]=min(lft[a], b);
		rght[a]=max(rght[a], b);
	}
	FOR(i, 1, q){
		cin>>a;
		cols.pb(a);
	}
	sort(cols.begin(), cols.end());
	dp[1][0]=inf;
	if(ciek[1]) dp[1][1]=rght[1]-1;
	else{
		lft[1]=rght[1]=1;
		dp[1][1]=0;
	}
	FOR(i, 2, n){
		if(!ciek[i]) continue;
		dp[i][0]=min(dp[poprz][0]+dist(poprz, lft[poprz], i, rght[i]), dp[poprz][1]+dist(poprz, rght[poprz], i, rght[i]))+rght[i]-lft[i];
		dp[i][1]=min(dp[poprz][0]+dist(poprz, lft[poprz], i, lft[i]), dp[poprz][1]+dist(poprz, rght[poprz], i, lft[i]))+rght[i]-lft[i];
		poprz=i;
	}
	cout<<min(dp[poprz][0], dp[poprz][1])<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}