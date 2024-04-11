#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;
const int MAXT = 270000;

struct seg{
	lint tree[MAXT], lazy[MAXT];
	void lazydown(int p){
		tree[2*p] += lazy[p];
		tree[2*p+1] += lazy[p];
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	void upd(int s, int e, int ps, int pe, int p, lint v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] += v;
			lazy[p] += v;
			return;
		}
		lazydown(p);
		int pm = (ps+pe)/2;
		upd(s, e, ps, pm, 2*p, v);
		upd(s, e, pm+1, pe, 2*p+1, v);
		tree[p] = min(tree[2*p], tree[2*p+1]);
	}
	lint query(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 5e18;
		if(s <= ps && pe <= e) return tree[p];
		lazydown(p);
		int pm = (ps+pe)/2;
		return min(query(s, e, ps, pm, 2*p), query(s, e, pm+1, pe, 2*p+1));
	}

}seg;

int q;
int t[MAXN], x[MAXN], l[MAXN], r[MAXN], vel[MAXN];
lint val[MAXN];
map<int, int> mp;

void upd(int x, lint v){
	seg.upd(x, q, 0, q, 1, v - val[x]); // partial sum add
	val[x] = v;
}

int query(int st, int ed, int v){
	lint ret = seg.query(st-1, st-1, 0, q, 1);
	if(seg.query(st, ed - 1, 0, q, 1) - ret > v){
		return -1;
	}
	int s = st, e = ed - 1;
	while(s != e){
		int m = (s + e) / 2;
		if(seg.query(st, m, 0, q, 1) - ret <= v) e = m;
		else s = m + 1;
	}
	return s;
}

lint getsum(int s, int e){
	lint ret = seg.query(e, e, 0, q, 1) - seg.query(s-1, s-1, 0, q, 1);
	return ret;
}

int main(){
	scanf("%d",&q);
	vector<int> v = {-1};
	for(int i=0; i<q; i++){
		scanf("%d",&t[i]);
		if(t[i] == 1){
			scanf("%d %d",&x[i],&vel[i]);
		}
		if(t[i] == 2){
			scanf("%d",&x[i]);
		}
		if(t[i] == 3){
			scanf("%d %d %d",&l[i],&r[i],&vel[i]);
		}
		if(t[i] != 3) v.push_back(x[i]);
		else v.push_back(r[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	auto getcrd = [&](int x){
		return lower_bound(v.begin(), v.end(), x) - v.begin();
	};
	auto ERASE = [&](int x){
		upd(getcrd(x), 0);
		mp.erase(mp.find(x));
		auto l = mp.lower_bound(x);
		if(l != mp.begin()){
			auto prv = prev(l);
			if(l == mp.end()) upd(getcrd(prv->first), 0);
			else upd(getcrd(prv->first), 1ll * (l->first - prv->first) * prv->second);
		}
	};
	auto INSERT = [&](int x, int v){
		auto l = mp.lower_bound(x);
		if(l != mp.begin()){
			auto prv = prev(l);
			upd(getcrd(prv->first), 1ll * (x - prv->first) * prv->second);
		}
		mp[x] = v;
		l = mp.find(x);
		if(next(l) != mp.end()){
			auto nxt = next(l);
			upd(getcrd(x), 1ll * (nxt->first - x) * v);
		}
	};
	for(int i=0; i<q; i++){
		if(t[i] == 1){
			if(mp.find(x[i]) != mp.end()){
				ERASE(x[i]);
			}
			INSERT(x[i], vel[i]);
		}
		if(t[i] == 2){
			ERASE(x[i]);
		}
		if(t[i] == 3){
			if(vel[i] == 0){
				printf("%d\n", l[i]);
				continue;
			}
			int st = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
			int ed = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
			if(st == ed){
				puts("-1");
				continue;
			}
			bool flag = 0;
			if(mp.find(r[i]) == mp.end()){
				INSERT(r[i], 0);
				flag = 1;
			}
			lint ret = 0;
			int interesting = query(st, ed, -vel[i]);
			if(interesting != -1){
				ret = getsum(st, interesting);
				auto itr = mp.upper_bound(v[interesting]);
				int prv_speed = mp[v[interesting]];
				lint eudori = -vel[i] - ret;
				printf("%.10f\n", itr->first - 1.0 * eudori / (-prv_speed));
			}
			else{
				puts("-1");
			}
			if(flag){
				ERASE(r[i]);
			}
		}
	}
}