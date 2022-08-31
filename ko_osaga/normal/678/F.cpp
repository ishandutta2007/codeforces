#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

vector<pi> tree[1050000];

void add(int s, int e, int ps, int pe, int p, pi v){
	if(e < ps || pe < s) return;
	if(s <= ps && pe <= e){
		tree[p].push_back(v);
		return;
	}
	int pm = (ps + pe) / 2;
	add(s, e, ps, pm, 2*p, v);
	add(s, e, pm+1, pe, 2*p+1, v);
}

vector<pi> tmp;

bool ok(pi a, pi b, pi c){
	return 1ll * (b.first - a.first) * (c.second - b.second) <= 1ll * (b.first - c.first) * (a.second - b.second);
}

void solve(int x){
	sort(tree[x].begin(), tree[x].end(), [&](const pi &a, const pi &b){
		return pi(a.first, -a.second) < pi(b.first, -b.second);
	});
	tmp.clear();
	int pv = -2e9;
	for(auto &i : tree[x]){
		if(i.first == pv) continue;
		pv = i.first;
		while(tmp.size() >= 2 && !ok(tmp[tmp.size()-2], tmp.back(), i)){
			tmp.pop_back();
		}
		tmp.push_back(i);
	}
	tree[x] = tmp;
}

void dfs(int s, int e, int p){
	solve(p);
	if(s == e) return;
	int m = (s+e)/2;
	dfs(s, m, 2*p);
	dfs(m+1, e, 2*p+1);
}

lint nodequery(int p, int x){
	if(tree[p].empty()) return -5e18;
	auto func = [&](int q){
		return 1ll * tree[p][q].first * x + tree[p][q].second;
	};
	int s = 0, e = (int)tree[p].size() - 1;
	while(s != e){
		int m = (s+e)/2;
		if(func(m) < func(m+1)) s = m+1;
		else e = m;
	}
	return func(s);
}

lint query(int pos, int s, int e, int p, int x){
	lint ret = nodequery(p, x);
	if(s == e) return ret;
	int m = (s+e)/2;
	if(pos <= m) ret = max(ret, query(pos, s, m, 2*p, x));
	else ret = max(ret, query(pos, m+1, e, 2*p+1, x));
	return ret;
}

struct ins{
	int s, e, x, y;
};

int q;
vector<ins> inserts;
pi inslis[300005];
bool vis[300005];
int cnt[300005], qry[300005];

int main(){
	int inp;
	cin >> inp;
	for(int i=1; i<=inp; i++){
		int t;
		scanf("%d",&t);
		if(t == 1){
			vis[i] = 1;
			scanf("%d %d",&inslis[i].first, &inslis[i].second);
		}
		if(t == 2){
			int x;
			scanf("%d",&x);
			inserts.push_back({cnt[x] + 1, cnt[i-1], inslis[x].first, inslis[x].second});
			vis[x] = 0;
		}
		if(t == 3){
			scanf("%d",&qry[i]);
			cnt[i]++;
		}
		cnt[i] += cnt[i-1];
	}
	if(cnt[inp] == 0) return 0;
	for(int i=1; i<=inp; i++){
		if(vis[i]){
			inserts.push_back({cnt[i] + 1, cnt[inp], inslis[i].first, inslis[i].second});
		}
	}
	for(auto &i : inserts){
		add(i.s, i.e, 1, cnt[inp], 1, pi(i.x, i.y));
	}
	dfs(1, cnt[inp], 1);
	for(int i=1; i<=inp; i++){
		if(cnt[i] != cnt[i-1]){
			lint t = query(cnt[i], 1, cnt[inp], 1, qry[i]);
			if(t < -4e18) puts("EMPTY SET");
			else printf("%lld\n", t);
		}
	}
}