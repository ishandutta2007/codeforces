/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

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
    size_t operator()(pair<int64_t,int64_t> Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}

#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 T){
    const static long long N = (long long)(1e18);
    if (T < 0){
        os << '-';
        T *= -1;
    }
    unsigned long long a = T / N, b = T % N;
    if (a == 0)
        return os << b ;
    os << a;
    __int128 mul = 10;
    while( mul*b < N){
        os << '0';
        mul *= 10;
    }
    return os << b;
}
istream& operator >> (istream& is, __int128& T){
    string U;
    is >> U;
    T = 0;
    size_t pos = 0;
    int mul = 1;
    if (U[pos] == '-'){
        ++pos;
        mul *= -1;
    }
    for(; pos < U.size(); ++pos){
        T *= 10;
        T += (U[pos] - '0');
    }
    T *= mul;

    return is;
}
#endif
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
template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
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

#define For(i,n) for(int i = 0; i < (int) n; ++i)
#define Rep(i,n) for(int i = 1; i <= (int) n; ++i)
#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/

const int mod=1e9+7;

/*/-----------------------------Code begins----------------------------------/*/



const int N = 2e5 + 10;
int l[N], r[N], t[N], idx[N];


vector<int> pos[2*N];


int seg[8*N][2], laz[8*N][2];


#define M ((s + e) /2)

void rmvLaz(int node,int s,int e,int id){
	if (laz[node][id] != 0){
		seg[node][id] += laz[node][id];
		if (s != e){
			laz[2*node][id] += laz[node][id];
			laz[2*node + 1][id] += laz[node ][id];
		}
		laz[node][id] = 0;
	}
}

void update(int node,int s,int e,int l,int r, int v,int id){
	rmvLaz(node,s,e,id);
	if (e < l || s > r || l > r){
		return;
	}
	if (l <= s && e <= r){
		laz[node][id] += v;
		rmvLaz(node,s,e,id);
		return;
	}

	update(2*node,s,M,l,r,v,id);
	update(2*node + 1, M + 1, e, l, r, v, id);

	seg[node][id] = max(seg[2*node][id], seg[2*node + 1][id]);
	assert(laz[node][id] == 0);

}


void update2(int node,int s,int e,int l,int v,int id){
	rmvLaz(node,s,e,id);

	if (e < l || s > l)
		return;
	if (s == e){
		assert(l == s);
		seg[node][id] = max(seg[node][id],v);
		return;
	}
	update2(2*node,s,M,l,v,id);
	update2(2*node + 1, M + 1,e , l,v,id);
	seg[node][id] = max(seg[2*node][id], seg[2*node + 1][id]);
	assert(laz[node][id] == 0);
}

int query(int node,int s,int e,int l,int r,int id){
	rmvLaz(node,s,e,id);
	assert(laz[node][id] == 0);

	if (e <l || s> r)
		return 0;

	if (l <= s && e <= r){
		return seg[node][id];
	}

	return max(query(2*node,s,M,l,r,id), query(2*node + 1,M + 1, e, l, r, id));


}

// int query(int node,int s,int e,int l,int r,int val,int id){
// 	if (e < l || s > r)
// 		return 0;

// 	if (l <= s && e <= r){
// 		return seg[node][id].order_of_key(val);
// 	}
// 	int mid = (s + e) >> 1;
// 	return query(2*node,s,mid,l,r,val,id) + query(2*node + 1, mid + 1, e, l, r, val,id);
// }

bool cmp(int i,int j){
	if (l[i] == l[j])
		return r[i] < r[j];
	return l[i] < l[j];
}
void solve(){
    int n;
    cin >> n;
    vector<int> T;
    for(int i = 0; i < n; ++i){
    	cin >> l[i] >> r[i] >> t[i];
    	--t[i];
    	T.push_back(l[i]);
    	T.push_back(r[i]);
    }

    sort(all(T));

    T.erase(unique(all(T)), T.end());
    
    assert(T.size() <= 2*n);
    for(int i = 0; i < n; ++i){
    	l[i] = upper_bound(T.begin(),T.end(),l[i]) - T.begin();
    	r[i] = upper_bound(T.begin(),T.end(),r[i]) - T.begin();

    	assert(l[i] <= T.size() && l[i] >= 1 && r[i] <= T.size() && r[i] >= 1);
    	// update(1,1,T.size(),l[i],r[i],t[i] - 1);
    	pos[r[i]].push_back(i);
    	
    }



    for(int id = 1; id <= T.size(); ++id){
    	for(auto i: pos[id]){
    		assert(r[i] == id);
    		update(1,0,T.size(), 0, l[i] - 1, 1, t[i] ^ 1);

    		
    	}
    	for(auto tt : {0,1}){
    		ll q0 = query(1,0,T.size(), 0, id,tt ^ 1);

			update2(1,0,T.size(),id,q0,tt);
    	}
		
    }

    cout << max(query(1,0,T.size(),0,T.size(),1), query(1,0,T.size(),0,T.size(),0)) << endl;
    // vector<int> dp(n + 1,0);

    // for(int j = 0; j < n; ++j){
    // 	int id = U[j].second;

    // 	int col = t[id];
    // 	int lef = l[id];
    // 	dp[j + 1] = dp[j];
    // 	if (col == 1){
    // 		auto it = lower_bound(all(U2),make_pair(lef,-1)) - U2.begin();
    // 		if (it == 0){
    // 			dp[j + 1] = max(dp[0] +  query(1,1,T.size(),1, r[id], r[id], 1) , dp[j + 1]);
    // 		}
    // 		else{
    // 			dp[j + 1] = max(dp[j + 1], dp[it] + query(1,1,T.size(),l[U2[it - 1].second] + 1,r[id], r[id],1 ));
    // 		}
    // 	}
    // 	else{
    // 		auto it = lower_bound(all(U1), make_pair(lef, -1)) - U1.begin();

    // 		if (it == 0){
    // 			dp[j + 1] = max(dp[j + 1], dp[0] + query(1,1,T.size(), 1, r[id], r[id], 0));

    // 		}
    // 		else{
    // 			dp[j + 1] = max(dp[j + 1], dp[it] + query(1,1,T.size(),l[U1[it - 1].second] + 1, r[id], r[id], 1));
    // 		}
    // 	}
    // }
    // trace(dp);


    // sort(idx,idx + n, cmp);





    // for(int idd = 0; idd < n; ++idd){
    // 	int i = idx[idd];

    	
    // }
}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}