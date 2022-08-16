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

const ll INF = 1LL<<50;
template<class T>
struct segtree{
    vector<T> tree, lazy;
    bool lazy_updates;
    int n;
    segtree(){}
    segtree(int _n, bool l = false){
        n = _n;
        tree.resize(4 * n, default_value());
        lazy_updates = l;
        if(l) lazy.resize(4 * n, 0);
    }
    
    T default_value(){
        return -INF;
    }

    T func(T a, T b){
        return max(a, b);
    }
 
    void update(int i, T val, int s, int e, int ind = 1){
        if(s > i || e < i) return;
        if(s == e){
            tree[ind] = val;
            return;
        }
        int mid = (s + e) >> 1;
        update(i, val, s, mid, ind << 1);
        update(i, val, mid + 1, e, ind << 1 | 1);
        tree[ind] = func(tree[ind << 1], tree[ind << 1 | 1]);
    }
 
    T get(int l, int r, int s, int e, int ind = 1){
        if(lazy_updates) push(s, e, ind);
        if(s > r || e < l) return default_value();
        if(s >= l && e <= r) return tree[ind];
        int mid = (s + e) >> 1;
        return func(get(l, r, s, mid, ind << 1), get(l, r, mid + 1, e, ind << 1 | 1));
    }
 
    void push(int s, int e, int ind){
        tree[ind] += lazy[ind];
        if(s != e){
            lazy[ind << 1] += lazy[ind];
            lazy[ind << 1 | 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    void range_update(int l, int r, T x, int s, int e, int ind = 1){
        push(s, e, ind);
        if(l > e || r < s) return;
        if(s >= l && e <= r){
            lazy[ind] += x;
            push(s, e, ind);
            return;
        }
        int mid = (s + e) >> 1;
        range_update(l, r, x, s, mid, ind << 1);
        range_update(l, r, x, mid + 1, e, ind << 1 | 1);
        tree[ind] = func(tree[ind << 1], tree[ind << 1 | 1]);
    }
    void update(int i, T v){
        update(i, v, 1, n);
    }
    void range_update(int l, int r, T x){
        range_update(l, r, x, 1, n);
    }
    T get(int l, int r){
        return get(l, r, 1, n);
    }
};

const int MAXV = 1e6 + 10;
const int N = 200005;
int a[N], ca[N], b[N], cb[N], x[N], y[N], z[N];
vector<int> addition[MAXV];
ll bestCost[MAXV], bestCost2[MAXV];
int main(){
	segtree<ll> st(MAXV - 1, true);
	int n, m, p;
	sd(n); sd(m); sd(p);
	fill(bestCost, bestCost + MAXV, -INF);
	fill(bestCost2, bestCost2 + MAXV, -INF);
	for(int i = 1; i <= n; i++){
		sd(a[i]); sd(ca[i]);
		bestCost[a[i]] = max(bestCost[a[i]], -(ll)ca[i]);
	}

	for(int i = 1; i <= m; i++){
		sd(b[i]); sd(cb[i]);
		bestCost2[b[i]] = max(bestCost2[b[i]], -(ll)cb[i]);
	}

	for(int i = (MAXV - 2); i >= 0; i--) bestCost[i] = max(bestCost[i + 1], bestCost[i]);
	for(int i = (MAXV - 2); i >= 0; i--){
		bestCost2[i] = max(bestCost2[i + 1], bestCost2[i]);
		st.update(i, bestCost2[i]);
	}

	for(int i = 1; i <= p; i++){
		sd(x[i]); sd(y[i]); sd(z[i]);
		addition[x[i] + 1].push_back(i);
	}
	ll ans = bestCost[0] + bestCost2[0];
	for(int i = 0; i < MAXV; i++){
		if(!addition[i].empty()){
			for(int j : addition[i]){
				st.range_update(y[j] + 1, st.n, z[j]);
			}
			ans = max(ans, st.get(1, st.n) + bestCost[i]);
		}
	}
	printf("%lld\n", ans);
}