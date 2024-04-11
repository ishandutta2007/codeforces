#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
typedef pair<int, int> pi;

struct AAAA{
	int n, cnt[MAXN];

	struct seg{
		struct node{
			int sum, maxv, maxfrm;
		}tree[530000];
		int lim;
		void init(int n){
			for(lim = 1; lim <= n; lim <<= 1);
		}
		node merge(node a, node b){
			node ret;
			ret.sum = a.sum + b.sum;
			if(a.maxv >= a.sum + b.maxv){
				ret.maxv = a.maxv;
				ret.maxfrm = a.maxfrm;
			}
			else{
				ret.maxv = a.sum + b.maxv;
				ret.maxfrm = b.maxfrm;
			}
			return ret;
		}
		void set(int x, int v){
			x += lim;
			tree[x] = {v, max(v, 0), x - lim};
			while(x > 1){
				x >>= 1;
				tree[x] = merge(tree[2*x], tree[2*x+1]);
			}
		}
		node query(){ return tree[1]; }
	}seg;

	struct intv{
		int s, e, v;
		bool operator<(const intv &i)const{
			return pi(e, v) < pi(i.e, i.v);
		}
	}a[MAXN];

	struct rmq{
		pi tree[530000];
		int lim;
		void init(int n){
			for(lim = 1; lim <= n; lim <<= 1);
			fill(tree, tree + 530000, pi(1e9, 1e9));
		}
		void add(int x, pi v){
			x += lim;
			tree[x] = v;
			while(x > 1){
				x >>= 1;
				tree[x] = min(tree[2*x], tree[2*x+1]);
			}
		}
		pi query(int s, int e){
			s += lim;
			e += lim;
			pi ret(1e9, 1e9);
			while(s < e){
				if(s%2 == 1) ret = min(ret, tree[s++]);
				if(e%2 == 0) ret = min(ret, tree[e--]);
				s >>= 1;
				e >>= 1;
			}
			if(s == e) ret = min(ret, tree[s]);
			return ret;
		}
	}rmq;

	vector<intv> st[MAXN];
	pi orv[MAXN];

	vector<int> orz(vector<int> v){
		n = v.size() / 2;
		for(int i=1; i<=n; i++){
			a[i].s = v[2*i-2];
			a[i].e = v[2*i-1];
			orv[i] = pi(a[i].s, a[i].e);
			a[i].v = i;
		}
		sort(a+1, a+n+1);
		for(int i=1; i<=n; i++){
			st[a[i].s].push_back(a[i]);
			cnt[i]--;
			cnt[a[i].e]++;
		}
		seg.init(n);
		rmq.init(n);
		for(int i=1; i<=n; i++) seg.set(i, cnt[i]);
		vector<int> ans;
		for(int i=1; i<=n; i++){
			int lst = i;
			cnt[i]++;
			seg.set(i, cnt[i]);
			if(seg.query().maxv > 0) lst = seg.query().maxfrm;
			else lst = n;
			for(auto &j : st[i]){
				auto it = lower_bound(a + 1, a + n + 1, j) - a;
				rmq.add(it, pi(j.v, it));
			}
			int l = lower_bound(a + 1, a + n + 1, (intv){-1, lst, 2222222}) - a;
			auto k = rmq.query(1, l - 1);
			int ev = orv[k.first].second;
			rmq.add(k.second, pi(1e9, 1e9));
			cnt[ev]--;
			seg.set(ev, cnt[ev]);
			ans.push_back(k.first);
		}
		return ans;
	}
}F, G;

int n;
pi a[MAXN];

int f[MAXN];
vector<int> rev(vector<int> v){
	for(int i=0; i<v.size(); i++) f[v[i]] = i + 1;
	return vector<int>(f+1, f + n + 1);
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d %d",&a[i].first,&a[i].second);
	vector<int> sexF, sexG;
	for(int i=1; i<=n; i++){
		sexF.push_back(a[i].first);
		sexF.push_back(a[i].second);
		sexG.push_back(a[n+1-i].first);
		sexG.push_back(a[n+1-i].second);
	}
	auto X = F.orz(sexF);
	auto Y = G.orz(sexG);
	for(auto &i : Y) i = n + 1 - i;
	X = rev(X);
	Y = rev(Y);
	if(X == Y){
		puts("YES");
		for(auto &i : X) printf("%d ", i);
	}
	else{
		puts("NO");
		for(auto &i : X) printf("%d ", i);
		puts("");
		for(auto &i : Y) printf("%d ", i);
	}
}