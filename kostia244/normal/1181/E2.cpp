#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using oset = tree<int, null_type, T, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<18, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mx = maxn-1;
struct segtree {
	struct node {
		node *l, *r;
		int lazy;
		pi val;
		node(int x = 0, int p = -1) : val(x, p), lazy(0), l(0), r(0) {};
	};
	using pnode = node*;
	deque<node> karan;
	pnode newnode(int x = 0, int p = -1) {
		karan.emplace_back(x, p);
		return &karan.back();
	}
	pnode rt= nullptr;
	void clear() {
		rt = nullptr;
	}
	void push(pnode &v, int l, int r) {
		if(!v) return;
		v->val.first += v->lazy;
		if(l != r) {
		if(!v->l) v->l = newnode(0, l);
		if(!v->r) v->r = newnode(0, 1 + (l+r)/2);
		v->l->lazy += v->lazy;
		v->r->lazy += v->lazy;
		}
		v->lazy = 0;
	}
	pi get(int l, int r) {
		if(l>r) return {1<<30, -1};
		return get(0, mx, l, r, rt);
	}
	pi get(int l, int r, int ql, int qr, pnode &v) {
		push(v, l, r);
		if(r < ql || qr < l) return {1<<30, -1};
		if(!v) v = newnode(0, l);
		if(ql <= l && r <= qr) return v->val;
		int mid = (l+r)/2;
		return min(get(l, mid, ql, qr, v->l), get(mid+1, r, ql, qr, v->r));
	}
	void upd(int l, int r, int x) {
		if(l>r) return;
		upd(0, mx, l, r, x, rt);
	}
	void upd(int l, int r, int ql, int qr, int x, pnode &v) {
		push(v, l, r);
		if(r < ql || qr < l) return;
		//cout << l << " " << r << " " << ql << " " << qr << '\n';
		if(!v) v = newnode(0, l);
		if(ql <= l && r <= qr) {
			v->lazy = x;
			push(v, l, r);
			return;
		}
		int mid = (l+r)/2;
		upd(l, mid, ql, qr, x, v->l);
		upd(mid + 1, r, ql, qr, x, v->r);
		v->val = min(v->l?v->l->val:pi{0, l}, v->r?v->r->val:pi{0, mid+1});
	}
};
int n, lx[maxn], rx[maxn], ly[maxn], ry[maxn];
#define lesspp(x, y, a, b) (x<a||(x==a&&y<b))
struct xcmp {
	bool operator() (const int &i, const int &j) const {
		return lesspp(lx[i], ly[i], lx[j], ly[j]);
	}
};
struct ycmp {
	bool operator() (const int &i, const int &j) const {
		return lesspp(ly[i], lx[i], ly[j], lx[j]);
	}
};
void dfs(oset<xcmp> x, oset<ycmp> y) {
	if(x.size()<=1) return;
	segtree cx, cy;
	for(auto i : x) {
		cx.upd(lx[i]+1, rx[i]-1, 1);
		//cout <<"x["<< lx[i]+1 << " " << rx[i]-1 << "] " << 1 << endl;
		cy.upd(ly[i]+1, ry[i]-1, 1);
		//cout <<"y["<< ly[i]+1 << " " << ry[i]-1 << "] " << 1 << endl;
		//for(int i = 0; i < 3; i++) cout << cy.get(i, i).first << " ";cout << endl;
		//return;//remove
	}
	//cout << cx.rt->val.first << " " << cx.rt->val.second << '\n';
	//cout << cy.rt->val.first << " " << cy.rt->val.second << '\n';
	//for(int i = 0; i < 3; i++) cout << cx.get(i, i).first << " ";cout << endl;
	//for(int i = 0; i < 3; i++) cout << cy.get(i, i).first << " ";cout << endl;
	//cout << x.size() << " " << y.size() << " <3" << endl;
	while(x.size()>1) {
		auto p = cx.get(lx[*x.begin()]+1, lx[*x.rbegin()]);
		//cout << p.first << " " << p.second << " cut < " << lx[*x.rbegin()] << endl;
		if(p.first==0) {
			int cut = p.second;
			int LEQ = x.order_of_key(cut+1);
			oset<xcmp> nx;
			oset<ycmp> ny;
			if(lx[*x.find_by_order(x.size()/2)] >= cut) {
				//cout << "xxcut " << cut << endl;
				while(lx[*x.begin()] < cut) {
					int t = *x.begin();
					x.erase(t);
					y.erase(t);
					cx.upd(lx[t]+1, rx[t]-1, -1);
					cy.upd(ly[t]+1, ry[t]-1, -1);
					nx.insert(t);
					ny.insert(t);
				}
				//cout << nx.size() << " " << ny.size() << '\n';exit(0);
			} else {
				//cout << "HER" << cut<<endl;
				while(lx[*x.rbegin()] >= cut) {
					int t = *x.rbegin();
					//cout << "HERE"<<endl;
					x.erase(t);
					y.erase(t);
					//cout << "HERE1"<<endl;
					cx.upd(lx[t]+1, rx[t]-1, -1);
					cy.upd(ly[t]+1, ry[t]-1, -1);
					//cout << "HERE2"<<endl;
					nx.insert(t);
					ny.insert(t);
					//cout << "HERE3"<<endl;
				}
			}
			//return;//REMOVE
			dfs(nx, ny);
			continue;
		}
		
		p = cy.get(ly[*y.begin()]+1, ly[*y.rbegin()]);
		if(p.first==0) {
			int cut = p.second;
			//cout << "ycut " << endl;
			//cout << cut << " ";
			oset<xcmp> nx;
			oset<ycmp> ny;
			if(ly[*y.find_by_order(y.size()/2)] >= cut) {
				//cout << "HER" << cut<<endl;
				while(ly[*y.begin()] < cut) {
					int t = *y.begin();
					x.erase(t);
					y.erase(t);
					cx.upd(lx[t]+1, rx[t]-1, -1);
					cy.upd(ly[t]+1, ry[t]-1, -1);
					nx.insert(t);
					ny.insert(t);
				}
			//cout << nx.size() << " " << ny.size() << '\n';
			//exit(0);
			} else {
				while(ly[*y.rbegin()] >= cut) {
					int t = *y.rbegin();
					x.erase(t);
					y.erase(t);
					cx.upd(lx[t]+1, rx[t]-1, -1);
					cy.upd(ly[t]+1, ry[t]-1, -1);
					nx.insert(t);
					ny.insert(t);
				}
			}
			//return;//REMOVE
			dfs(nx, ny);
			continue;
		}
		cout << "NO", exit(0);
	}
	if(x.size()>1) {cout << "NO", exit(0);}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	oset<xcmp> x;
	oset<ycmp> y;
	vi xc, yc;
	for(int i = 0; i < n; i++) {
		cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
		xc.pb(lx[i]), xc.pb(rx[i]), yc.pb(ly[i]), yc.pb(ry[i]);
	}
	sort(all(xc)), xc.erase(unique(all(xc)), xc.end());
	sort(all(yc)), yc.erase(unique(all(yc)), yc.end());
	for(int i = 0; i < n; i++) {
		lx[i] = lower_bound(all(xc), lx[i]) - xc.begin();
		rx[i] = lower_bound(all(xc), rx[i]) - xc.begin();
		ly[i] = lower_bound(all(yc), ly[i]) - yc.begin();
		ry[i] = lower_bound(all(yc), ry[i]) - yc.begin();
	}
	for(int i = 0; i < n; i++) x.insert(i), y.insert(i);
	dfs(x, y);
	cout << "YES";
	return 0;
}