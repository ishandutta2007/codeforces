#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 2005;
vector<int> X[N];
int x[N], y[N], c[N];
int cx[N], cy[N];
int rev_x[N], rev_y[N];

const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}

int f[N], pf[N];
int L;

struct segtree{
	vector<int> tree, rgt, lazy;
	int n;
	segtree(vector<int> v) : n(v.size()){
		tree.assign(4 * n + 10, 0);
		rgt.assign(4 * n + 10, 0);
		lazy.assign(4 * n + 10, -10);
		function<void(int, int, int)> make = [&](int s, int e, int ind){
			if(s == e){
				tree[ind] = mul(f[s], sub(L, v[s]));
				rgt[ind] = v[s];
				return;
			}
			int mid = (s + e) >> 1;
			make(s, mid, ind << 1);
			make(mid + 1, e, ind << 1 | 1);
			tree[ind] = add(tree[ind << 1], tree[ind << 1 | 1]);
			rgt[ind] = rgt[ind << 1 | 1];
		};
		make(0, n - 1, 1);
	}

	void push(int s, int e, int ind){
		if(lazy[ind] == -10) return;
		tree[ind] = mul(sub(pf[e], s == 0 ? 0 : pf[s - 1]), sub(L, lazy[ind]));
		rgt[ind] = lazy[ind];
		if(s != e){
			lazy[ind << 1] = lazy[ind << 1 | 1] = lazy[ind];
		}
		lazy[ind] = -10;
	}

	void update(int l, int r, int x, int s, int e, int ind){
		push(s, e, ind);
		if(l > e || s > r) return;
		if(s >= l && e <= r){
			lazy[ind] = x;
			push(s, e, ind);
			return;
		}
		int mid = (s + e) >> 1;
		update(l, r, x, s, mid, ind << 1);
		update(l, r, x, mid + 1, e, ind << 1 | 1);
		tree[ind] = add(tree[ind << 1], tree[ind << 1 | 1]);
		rgt[ind] = rgt[ind << 1 | 1];
	}

	int getFirst(int v, int s, int e, int ind){
		push(s, e, ind);
		if(s == e) return s;
		int mid = (s + e) >> 1;
		push(s, mid, ind << 1);
		if(rgt[ind << 1] >= v) return getFirst(v, s, mid, ind << 1);
		else return getFirst(v, mid + 1, e, ind << 1 | 1);
	}

	int getFirst(int v){
		return getFirst(v, 0, n - 1, 1);
	}

	int getSum(){
		return tree[1];
	}

	void update(int l, int r, int v){
		update(l, r, v, 0, n - 1, 1);
	}
};

signed main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n = 2000, k = 2; L = 1000000000;
	cin >> n >> k >> L;
	map<int, int> compress_x, compress_y;
	set<int> st_x = {-1, L}, st_y = {-1, L};

	int cnt_x = 0, cnt_y = 0;
	for(int i = 0; i < n; i++){
		x[i] = rand() % L; y[i] = rand() % L; c[i] = rand() % k + 1;
		cin >> x[i] >> y[i] >> c[i];
		c[i]--;
		st_x.insert(x[i]);
		st_y.insert(y[i]);
	}

	for(auto it : st_x){
		rev_x[cnt_x] = it;
		compress_x[it] = cnt_x++;
	}

	for(auto it : st_y){
		rev_y[cnt_y] = it;
		compress_y[it] = cnt_y++;
	}

	for(int i = 0; i < n; i++){
		cx[i] = compress_x[x[i]];
		cy[i] = compress_y[y[i]];
		X[cx[i]].push_back(i);
	}

	for(int i = 1; i < cnt_y; i++){
		f[i] = rev_y[i] - rev_y[i - 1];
		pf[i] = add(pf[i - 1], f[i]);
	}
	int ans = 0;
	
	for(int i = 1; i < cnt_x - 1; i++){
		vector<multiset<int>> positions(k);
		vector<vector<int>> at_y(cnt_y);
		for(int j = i; j < cnt_x; j++) for(int ind : X[j]){
			positions[c[ind]].insert(cy[ind]);
			at_y[cy[ind]].push_back(ind);
		}
		
		vector<int> mn(cnt_y);
		multiset<int> mx;
		vector<int> mn_pos(k, cnt_y - 1);
		for(int j = 0; j < k; j++) mx.insert(cnt_y - 1);
		for(int j = cnt_y - 1; j >= 0; j--){
			for(int ind : at_y[j]){
				mx.erase(mx.find(mn_pos[c[ind]]));
				mn_pos[c[ind]] = j;
				mx.insert(j);
			}
			mn[j] = rev_y[*mx.rbegin()];
		}
		for(int i = 1; i < cnt_y; i++) assert(mn[i] >= mn[i - 1]);
		segtree st(mn);
		int R = sub(rev_x[i], rev_x[i - 1]);
		
		int sm = 0;
		for(int j = cnt_x - 2; j >= i; j--){
			for(int ind : X[j + 1]){
				int col = c[ind];
				auto it = positions[col].lower_bound(cy[ind]);
				assert(*it == cy[ind]);
				auto it2 = it;
				auto it3 = it;
				int prv = 0, nxt = cnt_y - 1;
				if(it3 != positions[col].begin()){
					it3--;
					prv = *it3;
				}
				it2++;
				if(it2 != positions[col].end()){
					nxt = *it2;
				}
				positions[col].erase(it);
				int fst = st.getFirst(rev_y[nxt]); // first with >= rev_y[nxt]
				assert(fst <= nxt);

				if(prv + 1 < fst){
					int new_val = rev_y[nxt];
					st.update(prv + 1, fst - 1, new_val);
				}
			}
			int val = mul(sub(rev_x[j + 1], rev_x[j]), st.getSum());
			sm = add(sm, val);
		}
		ans = add(ans, mul(R, sm));
	}
	cout << ans << endl;
}