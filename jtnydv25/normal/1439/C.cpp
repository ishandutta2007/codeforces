#include <bits/stdc++.h>
using namespace std;

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

struct Data{
	ll sum;
	int mn;
};
const int INF = 1e9 + 10;

Data merge(const Data & A, const Data & B){
	return {A.sum + B.sum, min(A.mn, B.mn)};
}

struct segtree{
	vector<Data> tree;
	vector<int> lazy;
	int n;
	segtree(vector<int> a) : n(a.size()){
		tree.resize(4 * n + 10);
		lazy.resize(4 * n + 10);
		
		function<void(int, int, int)> make= [&](int s, int e, int ind){
			if(s == e){
				tree[ind] = {a[s], a[s]};
				return;
			}
			int mid = (s + e) >> 1;
			make(s, mid, ind << 1);
			make(mid + 1, e, ind << 1 | 1);
			tree[ind] = merge(tree[ind << 1], tree[ind << 1 | 1]);
		};
		make(0, n - 1, 1);
	}
	void push(int s, int e, int ind){
		int x = lazy[ind];
		if(!x) return;
		tree[ind].sum = x * (ll) (e - s + 1);
		tree[ind].mn = x;
		if(s != e){
			lazy[ind << 1] = lazy[ind << 1 | 1] = x;
		}
		lazy[ind] = 0;
	}
	void update(int l, int r, int x, int s, int e, int ind){
		push(s, e, ind);
		if(s > r || l > e) return;
		if(s >= l && e <= r){
			lazy[ind] = x;
			push(s, e, ind);
			return;
		}
		int mid = (s + e) >> 1;
		update(l, r, x, s, mid, ind << 1);
		update(l, r, x, mid + 1, e, ind << 1 | 1);
		tree[ind] = merge(tree[ind << 1], tree[ind << 1 | 1]);
	}

	int getFirst(int x, int s, int e, int ind){
		push(s, e, ind);
		if(s == e){
			return s;
		}
		int mid = (s + e) >> 1;
		push(s, mid, ind << 1);
		if(tree[ind << 1].mn >= x) return getFirst(x, mid + 1, e, ind << 1 | 1);
		else return getFirst(x, s, mid, ind << 1);
	}
	// first position with value < x
	int getFirst(int x){
		push(0, n - 1, 1);
		if(tree[1].mn >= x) return n;
		return getFirst(x, 0, n - 1, 1);
	}
	ll getSum(int l, int r, int s, int e, int ind){
		if(l > r) return 0;
		push(s, e, ind);
		if(s > r || l > e) return 0;
		if(s >= l && e <= r) return tree[ind].sum;
		int mid = (s + e) >> 1;
		return getSum(l, r, s, mid, ind << 1) + getSum(l, r, mid + 1, e, ind << 1 | 1);
	}
	int getFirstSum(ll sm, ll x, int s, int e, int ind){
		push(s, e, ind);
		if(s == e){
			return s;
		}
		int mid = (s + e) >> 1;
		push(s, mid, ind << 1);
		ll v = tree[ind << 1].sum + sm;
		if(v > x) return getFirstSum(sm, x, s, mid, ind << 1);
		else return getFirstSum(v, x, mid + 1, e, ind << 1 | 1);
	}
	void update(int r, int x){
		int h = getFirst(x); // first < x
		if(h > r) return;
		update(h, r, x, 0, n - 1, 1);
	}

	int getPos(int pos, ll val){
		push(0, n - 1, 1);
		ll s = getSum(0, pos - 1, 0, n - 1, 1);
		// first with sum > val + s
		if(s + val >= tree[1].sum) return n;

		// first position with sum > s + val
		return getFirstSum(0, s + val, 0, n - 1, 1);
	}
	
	int getNum(int pos, ll y){
		int ans = 0;
		while(pos != n){
			// while(a[pos] > y) pos++;
			pos = max(pos, getFirst(y + 1));
			if(pos == n) break;
			int pos2 = getPos(pos, y);
			assert(pos2 > pos);
			y -= getSum(pos, pos2 - 1, 0, n - 1, 1);
			ans += pos2 - pos;
			pos = pos2;
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	segtree st(a);
	while(q--){
		int type, x, y; cin >> type >> x >> y;
		x--;
		if(type == 1){
			st.update(x, y);
		} else{
			cout << st.getNum(x, y) << "\n";
		}
	}
}