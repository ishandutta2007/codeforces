
 // Krzysztof Boryczka
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

const int N=1e5+5;

int n, x, y;
vi jakie[N];
priority_queue<ii> q;

void solve(){
	int a, wolny;
	cin>>n>>x>>y;
	FOR(i, 1, n+1) jakie[i].clear();
	while(!q.empty()) q.pop();
	vi ans(n+1);
	vi input(n+1);
	FOR(i, 1, n){
		cin>>a;
		input[i]=a;
		jakie[a].pb(i);
	}
	FOR(i, 1, n+1){
		if(SIZE(jakie[i]) == 0) wolny=i;
		else q.push({SIZE(jakie[i]), i});
	}
	FOR(i, 1, x){
		auto v=q.top();
		q.pop();
		ans[jakie[v.nd].back()]=v.nd;
		jakie[v.nd].pop_back();
		v.st--;
		if(v.st) q.push(v);
	}
	y-=x;
	while(y>0){
		if(y&1 && y>=3 && SIZE(q)>2){
			auto v1=q.top();
			q.pop();
			auto v2=q.top();
			q.pop();
			auto v3=q.top();
			q.pop();
			ans[jakie[v1.nd].back()]=v2.nd;
			jakie[v1.nd].pop_back();
			ans[jakie[v2.nd].back()]=v3.nd;
			jakie[v2.nd].pop_back();
			ans[jakie[v3.nd].back()]=v1.nd;
			jakie[v3.nd].pop_back();
			v1.st--;
			v2.st--;
			v3.st--;
			if(v1.st) q.push(v1);
			if(v2.st) q.push(v2);
			if(v3.st) q.push(v3);
			y-=3;
			continue;
		}
		if(SIZE(q)<2){
			cout<<"NO"<<ent;
			return;
		}
		auto v1=q.top();
		q.pop();
		auto v2=q.top();
		q.pop();
		ans[jakie[v1.nd].back()]=v2.nd;
		jakie[v1.nd].pop_back();
		if(y==1) break;
		ans[jakie[v2.nd].back()]=v1.nd;
		jakie[v2.nd].pop_back();
		v1.st--;
		v2.st--;
		if(v1.st) q.push(v1);
		if(v2.st) q.push(v2);
		y-=2;
	}
	cout<<"YES"<<ent;
	FOR(i, 1, n) cout<<(ans[i] ? ans[i] : wolny)<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    FOR(te, 1, tt){
		// cout<<"Case #"<<te<<": ";
		solve();
	}
	// solve();
	return 0;
}