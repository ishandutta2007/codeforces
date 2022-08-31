#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

// 0-indexed
template<class T>
struct segtree{
	int n;
	vector<T> t;
	T def;
	inline T combine(T a, T b){
		return max(a, b);
	}
	segtree(vector<T> & inp, T def = T()) : n(sz(inp)), def(def){
		t.resize(2 * n, def);
		for(int i = 0; i < n; i++) t[n + i] = inp[i];
		for(int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
	}

	void modify(int p, T value) { // modify a[p] = value
		value = combine(value, t[p + n]); // if a[p] = combine(a[p], value)
		for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
	}

	T query(int l, int r) {  // compute on interval [l, r]
    r++;
		T resl = def, resr = def;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) resl = combine(resl, t[l++]);
			if (r&1) resr = combine(t[--r], resr);
		}
		return combine(resl, resr);
	}
};


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	vector<int> a(n), b(n);
	vector<int> vals;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		vals.push_back(a[i]);
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
		vals.push_back(b[i]);
		sum += abs(a[i] - b[i]);
	}
	sort(all(vals));
	vals.erase(unique(all(vals)), vals.end());
	int K = vals.size();
	vector<vector<int>> additions(K + 1), deletions(K + 1);
	function<int(int)> id = [&](int x){
		return lower_bound(all(vals), x) - vals.begin();
	};

	vector<int> L(n), R(n);
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			L[i] = min(a[i], b[i]), R[i] = max(a[i], b[i]);
			additions[id(L[i])].push_back(i);
			deletions[id(R[i])].push_back(i);
		}
	}

	vector<int> arr(K, 0);
	vector<segtree<int>> seg(2, segtree<int>(arr, 0));

	vector<multiset<int>> active(2);
	int ans = 0;
	for(int i = 0; i < K; i++){
		for(int ind : additions[i]){
			int type = a[ind] < b[ind];
			active[type].insert(L[ind]);
		}

		sort(all(deletions[i]), [&](int j, int k){return L[j] < L[k];});

		for(int ind : deletions[i]){
			int type = a[ind] < b[ind];
			int req = type ^ 1;
			int ID = id(L[ind]);
			
			auto it = active[req].lower_bound(L[ind]);
			if(it != active[req].end()) ans = max(ans, vals[i] - *it);
			active[type].erase(active[type].find(L[ind]));
			ans = max(ans, seg[req].query(ID, i));
			seg[type].modify(ID, R[ind] - L[ind]);
		}
	}
	cout << sum - 2 * ans << endl;
}