#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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

const int N = 1000006;
const int INF = 1e9 + 10;
struct segtree{
	vector<int> tree;
	int n;
	segtree(){}
	segtree(int _n){
		n = _n;
		tree.resize(4 * n + 5);
	}

	void update(int i, int val, int s, int e, int ind = 1){
		if(s > i || e < i) return;
		if(s == e){
			tree[ind] = val;
			return;
		}
		int mid = (s + e) >> 1;
		update(i, val, s, mid, ind << 1);
		update(i, val, mid + 1, e, ind << 1 | 1);
		tree[ind] = max(tree[ind << 1], tree[ind << 1 | 1]);
	}

	int get_max(int l, int r, int s, int e, int ind = 1){
		if(s > r || e < l) return -INF;
		if(s >= l && e <= r) return tree[ind];
		int mid = (s + e) >> 1;
		return max(get_max(l, r, s, mid, ind << 1), get_max(l, r, mid + 1, e, ind << 1 | 1));
	}
	void update(int i, int v){
		update(i, v, 1, n);
	}

	int get_max(int l, int r){
		return get_max(l, r, 1, n);
	}
};

segtree st[N];
vector<int> positions[N];
int mx[N];
int l[N];

int n, w;
int get(int i, int pos){
	int L = l[i];
	int ret = -INF;
	if(pos > l[i] || pos <= w - l[i]) ret = 0;
	int mn = max(1, l[i] - w + pos);
	int mx = min(pos, l[i]);
	return max(ret, st[i].get_max(mn, mx));
}

int main(){
	sd(n); sd(w);
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		sd(l[i]);
		st[i] = segtree(l[i]);
		for(int j = 1; j <= l[i]; j++){
			int x; sd(x);
			st[i].update(j, x);
			mx[i] = max(mx[i], x);
		}
		ans += mx[i];
		for(int j = 1; j <= l[i]; j++) positions[j].push_back(i);
		for(int j = max(l[i] + 1, w - l[i] + 1); j <= w; j++) positions[j].push_back(i);
	}

	for(int i = 1; i <= w; i++){
		ll val = ans;
		for(int j : positions[i]){
			val -= mx[j];
			val += get(j, i);
		}
		printf("%lld ", val);
	}
}