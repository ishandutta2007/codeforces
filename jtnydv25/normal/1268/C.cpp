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
const int N = 200005;
int a[N],pos[N];

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int M = 1e6;

template<class T>
struct Data{
	int child[2], bits[2], height;
	T val;
	Data(){
		child[0] = bits[0] = child[1] = bits[1] = val = height = 0;
	}
};
Data<ll> D[M];
// int child[M][2], bits[M][2], val[M], height[M];
const int MAX_BITS = 31;
int cnt = 0;
inline int clz(int N) {
    return N ? 31 - __builtin_clz(N) : -1;
}

template<int num_bits>
struct compressed_trie{
	int root;
	ll sm;
	compressed_trie(){
		root = ++cnt;
		D[root].height = num_bits;
		sm = 0;
	}
	void add(int x, int v){
		sm += v;
		int node = root;
		int pos = num_bits - 1;
		for(; ; ){
			Data<ll> & d = D[node];
			d.val += v;
			if(pos < 0) return;
			int dir = x >> pos & 1;
			if(!d.child[dir]){
				d.child[dir] = ++cnt;
				D[cnt].val += v;
				d.bits[dir] = x;
				return;
			}
			int y = d.bits[dir];
			int nxt = d.child[dir];
			int nxtH = D[nxt].height;
			y <<= (nxtH);
 
			int diff = clz(x^y);
 
			if(diff < nxtH){
				node = nxt;
				pos = nxtH - 1;
				x &= ((1<<nxtH) - 1);
				continue;
			}
 
			int yside = y >> diff & 1;
			int xside = x >> diff & 1;
 
			d.child[dir] = ++cnt;
			d.bits[dir] = x >> (diff + 1);
			D[cnt].val = D[nxt].val + v;
			D[cnt].height = diff + 1;
 
			D[cnt].child[yside] = nxt;
			D[cnt].bits[yside] = (y >> nxtH) & ( (1 << (diff + 1 - nxtH)) - 1);
			D[cnt].bits[xside] = x & ((1 << (diff + 1)) - 1);
			D[cnt].child[xside] = cnt + 1; ++cnt;
			D[cnt].val = v;
			return;
		}
	}
	ll order_of_key(int x){
		int node = root;
		int pos = num_bits - 1;
		ll ret = 0;
		bool to_print = (x == 11);
		for(; pos >= 0; ){
			int dir = x >> pos & 1;
			Data<ll> & d = D[node];	
			if(dir) ret += D[d.child[0]].val;
			if(!d.child[dir]){
				return ret;
			}
			int y = d.bits[dir];
			int nxt = d.child[dir];
			int nxtH = D[nxt].height;
			y <<= (nxtH);
 
			int diff =  clz(x^y);
 
			if(diff < nxtH){
				node = nxt;
				pos = nxtH - 1;
				x &= ((1<<nxtH) - 1);
				continue;
			}
			int xside = x >> diff & 1;
			if(xside) ret += D[nxt].val;
			return ret;
		}
		return ret;
	}
	void insert(int x){
		add(x, 1);
	}
};

ll getSum(int k){
	return (k * (ll) (k + 1)) / 2;
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		pos[a[i]]  = i;
	}

	compressed_trie<20> ct;
	compressed_trie<20> ct2;
	ordered_set os;
	int cnt = 0;
	ll inversions = 0;
	for(int k = 1; k <= n; k++){
		os.insert(pos[k]);
		inversions += k - 1 - os.order_of_key(pos[k]);
		ct.add(pos[k], 1);
		ct2.add(pos[k], pos[k]);
		int median = *os.find_by_order(k / 2) - k / 2;
		int lft = k / 2 + 1, rgt = k - lft;
		ll sm = ct2.order_of_key(median + k / 2 + 1);
		ll sm2 = getSum(k - 1);
		ll lftSum = median * (ll) lft + getSum(lft - 1) - sm;
		ll rgtSum = ct2.sm - sm - (sm2 - getSum(lft - 1)) - median * (ll) rgt;
		// trace(inversions);
		printf("%lld ", lftSum + rgtSum + inversions);
	}
}