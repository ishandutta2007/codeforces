#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
const int MAXN = 100005;

int n, a[MAXN], cnt;

struct bkt{
	int sz;
	int val[405];
	int lazy;
	int cnt = 0;
	int fucking;
	vector<pi> sorted;
	void build(int s, int e){
		vector<int> tmp;
		for(int i=s; i<=e; i++){
			tmp.push_back(a[i]);
		}
		sort(tmp.begin(), tmp.end());
		for(int i=0; i<tmp.size(); ){
			int e = i;
			while(e < tmp.size() && tmp[e] == tmp[i]) e++;
			sorted.push_back(pi(tmp[i], e - i));
			i = e;
		}
		sz = e - s + 1;
		for(int i=s; i<=e; i++){
			val[i - s] = a[i];
		}
	}
	void update(int x, int v){
		int prv = val[x];
		v -= lazy;
		val[x] = v;
		for(int i=0; i<sorted.size(); i++){
			if(sorted[i].first == prv){
				prv = i;
				break;
			}
		}
		if(sorted[prv].first + lazy < 0) cnt--;
		if(v + lazy < 0) cnt++;

		// erasing shit
		sorted[prv].second--;
		if(sorted[prv].second == 0) sorted.erase(sorted.begin() + prv);

		// inserting shit
		auto l = lower_bound(sorted.begin(), sorted.end(), pi(v, -1)) - sorted.begin();
		if(l != sorted.size() && sorted[l].first == v){
			sorted[l].second++;
		}
		else sorted.insert(sorted.begin() + l, pi(v, 1));
		fucking = lower_bound(sorted.begin(), sorted.end(), pi(-lazy, -1)) - sorted.begin();
	}
	void update(int s, int e, int v){

		if(s == 0 && e == sz - 1){
			lazy += v;
			while(fucking < sorted.size() && sorted[fucking].first + lazy < 0){
				cnt += sorted[fucking].second;
				fucking++;
			}
			while(fucking > 0 && sorted[fucking-1].first + lazy >= 0){
				fucking--;
				cnt -= sorted[fucking].second;
			}
			return;
		}
		for(int i=s; i<=e; i++) val[i] += v;
		vector<int> tmp;
		for(int i=0; i<sz; i++){
			tmp.push_back(val[i]);
		}
		sort(tmp.begin(), tmp.end());
		sorted.clear();
		for(int i=0; i<tmp.size(); ){
			int e = i;
			while(e < tmp.size() && tmp[e] == tmp[i]) e++;
			sorted.push_back(pi(tmp[i], e - i));
			i = e;
		}
		fucking = lower_bound(sorted.begin(), sorted.end(), pi(-lazy, -1)) - sorted.begin();
		cnt = 0;
		for(int i=0; i<fucking; i++) cnt += sorted[i].second;
	}
}B[255];

const int N = 400;

int query(){
	int ans = 0;
	for(int i=0; i<255; i++) ans += B[i].cnt;
	return ans;
}

void init(){
	for(int i=0; i+1<=n; i+=N){
		B[i/N].build(i + 1, min(i + N, n));
	}
}
void range_update(int s, int e, int v){
	s--, e--;
	for(int i=0; i<255; i++){
		int rs = max(s, N * i);
		int re = min(e, N * i + N - 1);
		if(rs <= re) B[i].update(rs - N * i, re - N * i, v);
	}
}

void update(int x, int v){
	x--;
	B[x / N].update(x % N, v);
}

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		while(x < MAXN){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

int q, t[MAXN];
int din[MAXN], dout[MAXN], piv, sz[MAXN], par[MAXN];
int chd[MAXN], piv2;
vector<int> gph[MAXN];

void dfs(int x){
	sz[x] = 1;
	for(auto &i : gph[x]){
		par[i] = x;
		dfs(i);
		sz[x] += sz[i];
	}
	sort(gph[x].begin(), gph[x].end(), [&](const int &a, const int &b){
		return sz[a] > sz[b];
	});
}

void hld(int x){
	din[x] = ++piv;
	if(gph[x].size()){
		chd[gph[x][0]] = chd[x];
		hld(gph[x][0]);
		for(int i=1; i<gph[x].size(); i++){
			chd[gph[x][i]] = gph[x][i];
			hld(gph[x][i]);
		}
	}
	dout[x] = piv;
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=2; i<=n; i++){
		int x;
		scanf("%d",&x);
		gph[x].push_back(i);
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&t[i]);
	}
	dfs(1);
	chd[1] = ++piv2;
	hld(1);
	for(int i=1; i<=n; i++) a[din[i]] = t[i];
	init();
	while(q--){
		int x;
		scanf("%d",&x);
		if(x < 0){
			x = -x;
			bit.add(din[x], -1);
			update(din[x], t[x] - bit.query(dout[x]) + bit.query(din[x]));
			x = par[x];
			while(x){
				int nxt = chd[x];
				range_update(din[nxt], din[x], 1);
				x = par[nxt];
			}
		}
		if(x > 0){
			bit.add(din[x], 1);
			update(din[x], 1e9);
			x = par[x];
			while(x){
				int nxt = chd[x];
				range_update(din[nxt], din[x], -1);
				x = par[nxt];
			}
		}
		printf("%d ", query());
	}
}