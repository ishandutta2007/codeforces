/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, ordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}

#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l,long long r){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
inline int64_t random_long(){
    uniform_int_distribution<int64_t> generator(LLONG_MIN,LLONG_MAX);
    return generator(rng);
}


/*/---------------------------Defines----------------------/*/
typedef vector<int> vi;
typedef pair<int,int> pii;

#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/

const int mod=1e9+7;
inline int add(int x,int y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline int sub(int x,int y){
    x-=y;
    if (x<0) return x+mod;
    return x;
}
inline int mul(int x,int y){
    return (x*1ll*y)%mod;
}
inline int power(int x,int y){
    int ans=1;
    while(y){
        if (y&1) ans=mul(ans,x);
        x=mul(x,x);
        y>>=1;
    }
    return ans;
}
inline int inv(int x){
    return power(x,mod-2);
}
/*/-----------------------------Code begins----------------------------------/*/


struct node{
	int l,r;
	bool empty;
	void combine(const node& a, const node& b){
		empty = (a.empty & b.empty);
		l = a.l;
		r = b.r;

		ll dif = min(a.r,b.l);

		l += b.l - dif;
		r += a.r - dif;

		// if (a.empty){
			// assert(a.r == 0);
			// l += b.l;
		// }
		// else{
			// r += max(a.r - b.l, 0);
		// }
	}
};
const int N = 2e5 + 100;
node seg[8*N];

#define M ((s+e)/2)
void build(int node,int s,int e){
	if (s == e){
		seg[node].l = 1;
		seg[node].r = 0;
		seg[node].empty = true;
		return;
	}
	build(2*node,s,M);
	build(2*node + 1, M+1 , e);

	seg[node].combine(seg[2*node],seg[2*node+1]);
}

void update(int node,int s,int e,int pos,int v){
	if ( pos < s || pos > e) return;


	if (s==e){
		assert(s == pos);
		if (v == 1){
			if (seg[node].l == 1){
				assert(seg[node].empty && seg[node].r == 0);

				seg[node].empty = false;
				seg[node].l = 0;
			}
			else{
				assert(!seg[node].empty && seg[node].l == 0);
				seg[node].r ++;
			}
		}
		else{
			assert(v == -1);
			assert(seg[node].l == 0 && !seg[node].empty);

			if (seg[node].r == 0){
				seg[node].l = 1;
				seg[node].empty = true;
			}
			else{
				--seg[node].r;
			}

		}
		return;
	}
	update(2*node,s,M,pos,v);
	update(2*node+1,M+1,e,pos,v);

	seg[node].combine(seg[2*node],seg[2*node+1]);
}


node query(int nod,int s,int e,int l,int r){
	if (r < s || l > e){
		node z;
		z.l = 0;
		z.r = 0;
		z.empty = true;
		return z;
	}

	if (l<= s && e<= r){
		return seg[nod];
	}

	node z;
	z.combine(query(2*nod,s,M,l,r),query(2*nod+1,M+1,e,l,r));
	return z;
}

void solve(){
    int n,m,k;
    cin>>n>>k>>m;
    build(1,1,2*n + 3);
    set<pair<int,int> > S;


    multiset<ll> T;
    for(int i = 0; i < m; ++i){
    	int x,y;
    	cin>>x>>y;

    	ll Y = y + abs(k-x);
    	assert(Y <= 2*n);
    	if (S.find({x,y}) != S.end()){
    		S.erase({x,y});

			update(1,1,2*n + 3,Y,-1);
			auto it1 = T.find(Y);

    			T.erase(it1);
    	}
    	else{
    		S.insert({x,y});

			update(1,1,2*n+3,Y,+1);

			T.insert(Y);
    	}


    	if (T.size() == 0) {
    		cout<<0<<endl;
    	}
    	else{
    		auto it = *(T.rbegin());
    		node ans = query(1,1,2*n+3,1,it);

    		ll ret = max(ans.r + it - n,0ll);

    		cout<<ret<<endl;
    	}

    }
}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}