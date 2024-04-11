#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pii;
const int mod = 1e9 + 9;

struct pi{
	int first, second;
	int idx;
	bool operator<(const pi &p)const{
		return make_pair(first, second) < make_pair(p.first, p.second);
	}
};

vector<pi> tree[270000];

bool bad(pi a, pi b, pi c){
	return 1ll * (b.second - c.second) * (b.first - a.first) <=
		1ll * (a.second - b.second) * (c.first - b.first);
}

void init(int s, int e, int p){
	if(s == e){
		tree[p].resize(1);
		scanf("%d %d",&tree[p][0].second,&tree[p][0].first);
		tree[p][0].idx = s;
		return;
	}
	int m = (s+e)/2;
	init(s, m, 2*p);
	init(m+1, e, 2*p+1);
	vector<pi> v(tree[2*p].size() + tree[2*p+1].size());
	merge(tree[2*p].begin(), tree[2*p].end(), tree[2*p+1].begin(), tree[2*p+1].end(), v.begin());
	for(auto &i : v){
		while(tree[p].size() >= 2 && bad(tree[p][tree[p].size()-2], tree[p].back(), i)){
			tree[p].pop_back();
		}
		tree[p].push_back(i);
	}
}

pii query(int s, int e, int ps, int pe, int p, int x){
	if(e < ps || pe < s) return pii(-1e18, -1);
	if(s <= ps && pe <= e){
		auto func = [&](int m){
			return 1ll * tree[p][m].first * x + tree[p][m].second;
		};
		int s = 0, e = tree[p].size()-1;
		while(s != e){
			int m = (s+e)/2;
			if(func(m) < func(m+1)) s = m+1;
			else e = m;
		}
		return pii(func(s), tree[p][s].idx);
	}
	int pm = (ps+pe)/2;
	return max(query(s, e, ps, pm, 2*p, x), query(s, e, pm+1, pe, 2*p+1, x));
}
int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	init(1, n, 1);
	while(m--){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		printf("%lld\n", query(s, e, 1, n, 1, x).second);
	}
}