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

const int N=1e5+5;

deque<ii> qwyn, qmax, qmin;
int dp[N], t[N];
int n, s, l, last;

void solve(){
	cin>>n>>s>>l;
	FOR(i, 1, n) cin>>t[i];
	memset(dp, inf, sizeof(dp));
	dp[0]=0;
	if(l==1) qwyn.pb({0, 0});
	FOR(i, 1, n){
		while(SIZE(qmax) && t[i]>=qmax.back().st) qmax.pop_back();
		qmax.pb({t[i], i});
		while(SIZE(qmin) && t[i]<=qmin.back().st) qmin.pop_back();
		qmin.pb({t[i], i});
		while(qmax.front().st-qmin.front().st>s){
			last=min(qmax.front().nd, qmin.front().nd);
			if(qmax.front().nd<qmin.front().nd) qmax.pop_front();
			else qmin.pop_front();
		}
		while(SIZE(qwyn) && qwyn.front().nd<last) qwyn.pop_front();
		if(SIZE(qwyn)) dp[i]=qwyn.front().st+1;
		if(i-l+1>=0){
			while(SIZE(qwyn) && qwyn.back().st>=dp[i-l+1]) qwyn.pop_back();
			qwyn.pb({dp[i-l+1], i-l+1});
		}
	}
	if(dp[n]>=inf) cout<<-1<<ent;
	else cout<<dp[n]<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}