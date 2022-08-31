/*/ Author: kal013 /*/
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
template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, ordered_set<T> S){
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

struct Node{
	int l[2],r[2],mx,tp,len;
	Node() {
		l[0] = 0; l[1] = 0; r[0] = 0; r[1] = 0; mx = 0; tp = 0; 
		// tp = -1  left, 1 right 0 mid
	}


	void comb(const Node&a, const Node& b){
		mx = max(a.mx,b.mx);

		mx =max( max (a.r[1] + b.l[0],mx) , max(a.r[1] + b.l[1] , a.r[0] + b.l[0] ) );

		for(int i = 0 ; i < 2; ++i){
			l[i] = a.l[i];
			r[i] = b.r[i];
		}

		len = a.len + b.len;
		if (a.tp == b.tp){
			tp = a.tp;
		}
		else{
			tp = 0;
		}
		// trace( tp, a.tp, b.tp);
		if (a.tp == -1){
			// assert(a.l[1] == 0 && a.r[1] == 0);
			l[0] += b.l[0];
		}
		else if (a.len == l[0]){

		}
		if (a.tp == 1){
			// assert(a.l[0] == 0 && a.r[0] == 0);

			l[1] += max(b.l[0],b.l[1]);
		}
		else if (a.len == l[1]){
			l[1] += b.l[0];
		}


		if (b.tp == -1 ){
			// assert(b.l[1] == 0 && b.r[1] == 0);
			r[0] += max(a.r[0],a.r[1]);
		}
		else if (b.len == r[0]){
			r[0] += a.r[1];
		}
		if (b.tp == 1){
			// assert(b.l[0] == 0 && b.r[0] == 0);

			r[1] += a.r[1];
		}

		mx = max(r[0],max(r[1],max(l[0],max(l[1],mx))));

		// if (a.tp == -1){
		// 	l[0] += b.l[0];

		// 	if (l[1] != 0 || a.r[1] != 0){
		// 		trace(l[1],a.l[1],a.l[0],a.r[1],a.r[0]);

		// 	}
		// 	assert(l[1] == 0 && a.r[1] == 0);

		// 	if (b.tp == -1){
		// 		r[0] += a.r[0];

		// 	}

		// }
		// else if (a.tp == 1){
		// 	assert(l[0] == 0 && a.r[0] == 0);
		// 	l[1] += max(b.l[1],b.l[0]);

		// 	if (b.tp == 1){
		// 		r[1] += a.r[1];
		// 	}
		// 	else if (b.tp == -1){
		// 		r[0] += 
		// 	}
		// }
		// else{
		// 	if (b.tp == 1){
		// 		r[1] += a.r[1];
		// 	}
		// 	else if (b.tp == -1){
		// 		r[0] += max(a.r[0],a.r[1]); 
		// 	}
		// }


		// if ( tp != 0){
			
		// 	assert(l[0] == r[0] && l[1] == r[1] && mx == max(l[0],l[1]));
		// }
	}

	// Node(const Node& a, const Node& b){

	// 	Node ret;
	// 	ret.mx = max(a.mx,b.mx);

	// 	if (a.tp == -1){
	// 		if (b.tp == -1)}{
	// 			assert(ret.mx == 0 && a.r == 0 && b.r ==0);
	// 			ret.tp = -1;
	// 			ret.l = a.l + b.l;
	// 			ret.r = 0; 
	// 		}
	// 		else if (b.tp == 0){
	// 			ret.tp = 0;
	// 			ret.r = b.r;
	// 			ret.l = 
	// 		}
	// 		else{

	// 		}
	// 	}
	// 	else if (a.tp == 0){

	// 	}
	// 	else if (a.tp == 1){

	// 	}
	// 	ret.l = a.l;
	// 	ret.r = b.r;

	// 	ret.mx = max {a.mx , b.mx , a.r + b.l}
	// }

};

const int N = 5e5 + 100;
Node seg[4 * N][2];
int laz[4* N];


string T;


inline void combine(int node){
	for(int i = 0; i < 2; ++i){
		seg[node][i].comb(seg[2*node][i],seg[2*node+1][i]);
		// seg[node][i].mx = max(seg[node][2*i].mx)
	}
}

#define M ((s+e)/2)



void build(int node,int s,int e){
	laz[node]= 0;
	if (s == e){
		if (T[s-1] == '<'){
			for(int i = 0; i<2; ++i){
				for(int j = 0; j < 2; ++j){
					seg[node][i].l[j] = (j^i^1);
					seg[node][i].r[j] = (j^i^1);
				}
				seg[node][i].tp = (i&1) ? 1:-1;
				// seg[node][i].l = (i^1)&1;
				// seg[node][i].r = i&1;
				seg[node][i].mx = 1;
				seg[node][i].len = 1;
			}
		}
		else{
			for(int i = 0; i<2; ++i){

				for(int j = 0; j < 2; ++j){
					seg[node][i].l[j] = (j^i);
					seg[node][i].r[j] = (j^i);
				}

				seg[node][i].tp = (i&1) ? -1 :1;
				// seg[node][i].r = (i^1)&1;
				// seg[node][i].l = i&1;
				seg[node][i].mx = 1;
				seg[node][i].len = 1;

			}	
		}
		// trace(node,s,e);
		// print(seg[node][0]);
		// print(seg[node][1]);
	}
	else{
		build(2*node,s,M);
		build(2*node + 1, M+1, e);
		combine(node);


		// trace(node,s,e);
		// print(seg[node][0]);
		// print(seg[node][1]);
	}
}


void rmv_laz(int node,int s,int e){
	if (laz[node]){
		laz[node] = 0;
		
		swap(seg[node][0],seg[node][1]);
		if (s!=e){
			laz[2*node] ^= 1;
			laz[2*node+1] ^= 1;
		}
	}
}


void update(int node,int s,int e,int l,int r){
	rmv_laz(node,s,e);

	if (l > e || s > r) return;



	if (l <= s && e <= r){
		laz[node] ^= 1;
		rmv_laz(node,s,e);
		return;
	}

	update(2*node,s,M,l,r);
	update(2*node+1,M+1,e,l,r);


	combine(node);


	// trace(node,s,e);

	// trace(seg[node][0].mx,seg[node][0].tp,seg[node][0].l[0],seg[node][0].l[1],seg[node][0].r[0],seg[node][0].r[1]);

}

Node query(int node,int s,int e,int l,int r){
	rmv_laz(node,s,e);
	assert( e >= l && s <= r);


	if (l <= s && e <= r){
		return seg[node][0];
	}


	if (M < l){
		return query(2*node + 1, M+1 , e, l,r);

	}

	if (M+1 > r){
		return query(2*node,s,M,l,r);
	}

	Node f;

	f.comb(query(2*node,s,M,l,r),query(2*node+1,M+1,e,l,r));
	return f;
}





void solve(){
 	int n,q;
 	cin>>n>>q;

 	cin>>T;

 	build(1,1,n);

 	Node ans = query(1,1,n,1,n);

 	for(int i = 0; i < q; ++i){
 		int l,r;
 		cin >>l >> r;

 		update(1,1,n,l,r);


 		Node ans = query(1,1,n,l,r);
// 	
 		int te = max(ans.mx,ans.l[0]);
 		te = max(te,ans.r[0]);
 		te = max(te, ans.r[1]);
 		te = max(te, ans.l[1]);
 		cout<< te <<endl;
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