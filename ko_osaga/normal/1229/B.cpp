#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 100005;
const int mod = 1e9 + 7;
int n;
vector<int> gph[MAXN];

lint a[MAXN], ret;

lint nwd(lint x, lint y){ return y ? nwd(y, x%y) : x; }

void dfs(int x, int p, vector<pi> stk){
	for(auto &i : stk){
		i.first = nwd(i.first, a[x]);
	}
	stk.emplace_back(a[x], 1);
	vector<pi> nstk;
	for(auto &i : stk){
		if(sz(nstk) && nstk.back().first == i.first){
			nstk.back().second += i.second;
		}
		else nstk.push_back(i);
	}
	stk = nstk;
	for(auto &i : stk){
		ret += i.first * i.second % mod;
		ret %= mod;
	}
	for(auto &i : gph[x]){
		if(i != p) dfs(i, x, stk);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<n; i++){
		int s, e; lint x; 
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	vector<pi> v;
	dfs(1, 0, v);
	cout << ret % mod << endl;
}
/*
int n;
pi a[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) cin >> a[i].first;
	for(int i=0; i<n; i++) cin >> a[i].second;
	sort(a, a + n);
	lint dap = 0;
	for(int i=1; i<n; i++){
		if(a[i-1].first == a[i].first){
			lint sum =0;
			for(int j=0; j<=i; j++){
				if(a[j].first & ~a[i].first) continue;
				sum += a[j].second;
			}
			dap = max(dap, sum);
		}
	}
	cout << dap << endl;
}*/