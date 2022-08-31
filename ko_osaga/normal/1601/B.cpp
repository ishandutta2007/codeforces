#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 300005;

int n, a[MAXN], b[MAXN];
int dist[MAXN], par[MAXN], pav[MAXN];

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for(int i = 1; i <= n; i++) scanf("%d",&b[i]);
	memset(dist, 0x3f, sizeof(dist));
	set<int> s;
	for(int i = 0; i < n; i++) s.insert(i);
	queue<int> que;
	auto enq = [&](int x, int d, int p, int v){
		if(dist[x] > d){
			dist[x] = d;
			par[x] = p;
			pav[x] = v;
			que.push(x);
		}
	};
	enq(n, 0, -1, -1);
	while(sz(que)){
		int x = que.front(); que.pop();
		auto it = s.lower_bound(x - a[x]);
		while(true){
			if(it == s.end() || *it > x) break;
			enq(*it + b[*it], dist[x] + 1, x, *it);
			it = s.erase(it);
		}
	}
	if(dist[0] > 1e8){
		puts("-1");
		return 0;
	}
	printf("%d\n", dist[0]);
	vector<int> seq;
	for(int i = 0; i < n; i = par[i]){
		seq.push_back(pav[i]);
	}
	reverse(all(seq));
	for(auto &i : seq) printf("%d ", i);
}