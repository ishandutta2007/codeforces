// Krzysztof Boryczka
#pragma GCC optimize("O3")
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

map<int, int> m;
priority_queue<ii> q;

vector<vi> ans;

void solve(){
	int n, a;
	cin>>n;
	FOR(i, 1, n){
		cin>>a;
		m[a]++;
	}
	for(auto &x: m) q.push({x.nd, x.st});
	while(SIZE(q)>2){
		auto v1=q.top();
		q.pop();
		auto v2=q.top();
		q.pop();
		auto v3=q.top();
		q.pop();
		ans.pb({v1.nd, v2.nd, v3.nd});
		v1.st--;
		v2.st--;
		v3.st--;
		if(v1.st) q.push(v1);
		if(v2.st) q.push(v2);
		if(v3.st) q.push(v3);
	}
	cout<<SIZE(ans)<<ent;
	for(auto &x: ans){
		sort(x.rbegin(), x.rend());
		for(auto &y: x) cout<<y<<sp;
		cout<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt){
	// 	cout<<"Case #"<<te<<": ";
	// 	solve();
	// }
	solve();
	return 0;
}