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

#define ll long long
#define F first
#define S second
#define pb push_back
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


vector<pair<ll,ll> > A;

bool done(){
	if (A[0].first == A[1].first) exit(0);
	if (A[1].first == A[2].first) exit(0);
	if (A[2].first == A[0].first) exit(0);
	return false;
	// return ((A[0].first == A[1].first)  || (A[1].first == A[2].first));
}
bool is_ap(vector<pair<ll,ll> > & A){
	sort(all(A));

	return (A[1].first - A[0].first == A[2].first - A[1].first);
}


int last_output;

void query(ll x){
	done();
	if (last_output == 0){
		exit(0);
		return;
	}

	cout << x << endl;

	cin >> last_output;

	if (last_output == -1){
		exit(0);
	}
	if (last_output == 0) {
		exit(0);
		return;
	}
	for(int i = 0 ; i < 3; ++i){
		if (A[i].second == last_output ){
			A[i].first += x;
		}
	}

	sort(all(A));


	// trace(A);
}
void do_ap(vector<pair<ll,ll> > & A){
	if (last_output == 0){
		return;
	}
	// assert(is_ap(A));
	sort(all(A));
	ll d= A[1].first - A[0].first;

	// assert( d > 0);
	query(d);
	query(3*d);
	query(d);
	query(d);
	query(2*d);
	done();
	exit(0);
	// assert(done() || last_output == 0);
}


int get_pos(){
	sort(all(A));
	for(int i = 0 ; i < 3; ++i){
		if (A[i].second == last_output){
			return i;
		}
	}
	done();
	// assert(false);
}
const ll INF = 3e9;
void solve(){
    last_output = 4;
    A.resize(3);
    for(int i = 0 ; i < 3; ++i){
    	cin >> A[i].first;
    	A[i].second = i + 1;
    }
    sort(all(A));
    cout << "First" << endl;

    if (is_ap(A)){
    	do_ap(A);
    	return;
    }

    query(INF);
    if (is_ap(A)){
    	do_ap(A);
    	return;
    }

    int id = get_pos();
    while (id != 1){
    	if (id == 0){
    		query(A[2].first - A[1].first);
    		query(A[1].first - A[0].first);
    	}
    	else{

    		query(A[1].first - A[0].first);
    	}
    	id = get_pos();

    }
    done();

    assert(id == 1 || done());


    ll x = A[1].first - A[0].first, y = A[2].first - A[1].first;

    while( !is_ap(A) && last_output != 0 && x < y && !done()){
    	id = get_pos();
    	done();
    	// assert(id == 1 || done());
    	query(x);
    	done();
    	id = get_pos();
    	// assert(id == 2);
    	query(x);

    	x *= 2;
    	// assert( x == A[1].first - A[0].first);
    }
	if (x > y){
    	query(x - y);

    }
    // assert(is_ap(A));
    do_ap(A);
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