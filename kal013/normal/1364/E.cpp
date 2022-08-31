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
const int N = 3000;
map<int,int > previous[N];

int query(int i,int j){
	++i ; ++j;
	if (previous[i].find(j) != previous[i].end()){
		return previous[i][j];
	}
	cout << "? " << i << " " << j << endl;
	int x;
	cin >> x;
	previous[i][j] = x;
	previous[j][i] = x;
	return x;
}



void do_zero(vector<int>& p, int x){
	p[x] = 0;
	for(int i = 0; i < p.size(); ++i){
		if (i != x && p[i] == -1){
			p[i] = query(i,x);
		}
	}

	cout << "! ";

	for(auto e:p){
		cout << e << " ";
	}
	cout << endl;

	exit(0);

}


inline int get_val(int id,vector<int>& z){
	map<int,int> cur;
	int ans = 0;
	for(int i = 0 ; i < 11; ++i){
		if (z[i] == id) continue;
		if (cur.find(z[i])!= cur.end()){
			ans |= (cur[z[i]] & (1ll << i));
		}
		else{
			cur[z[i]] = query(id,z[i]);
			ans |= (cur[z[i]] & (1ll << i));
		}
	}
	return ans;
}

void print_vec(vector<int>& V){
	cout << "! ";
	for(auto e: V){
		assert(e >= 0 && e < V.size());
		cout << e << " ";
	}
	cout << endl;
	exit(0);
}
void solve(){
	int n;
	cin >> n;


	vector<int> p(n,-1);
	vector<bool> ignore(n,false);

	vector<int> z(11,-1);


	int cnt_z = 11;

	while(cnt_z > 0){
		int i = random_long(0,n-1);
		int j = random_long(0,n-1);
		if ( i == j ) continue;
		int v = query(i,j);

		for(int k = 0; k < 11; ++k){
			if (z[k] == -1 && (v&(1ll<<k)) == 0){
				z[k] = i;
				--cnt_z;
			}
		} 
	}
	int id = 0;
	p[id] = get_val(id,z);


	for(int i = 1; i < n; ++i){
		int v = query(id,i);
		if ((v&p[id]) == v){
			id = i;
			p[id] = get_val(id,z);
		}
	}

	for(int i = 0 ; i < n; ++i){
		if (p[i] == -1) p[i] = query(i,id);
	}
	print_vec(p);
	// while(true){
	// 	vector<int> curr;
	// 	for(int i = 0; i < n; ++i){
	// 		if (!ignore[i]) curr.push_back(i);
	// 	}
	// 	if (curr.size() == 1){
	// 		do_zero(p,curr[0]);
	// 	}

	// 	int pos = random_long(0, curr.size() - 1);

	// 	vector<int> vals;
	// 	for(int i = 0; i < curr.size(); ++i){
	// 		if (i == pos) continue;

	// 		vals.push_back(query(curr[i],curr[pos]));
	// 	}
	// 	int cv = vals[0];

	// 	for(auto e: vals) cv &= e;

	// 	if (cv == 0){
	// 		do_zero(p,curr[pos]);
	// 	}
	// 	p[curr[pos]] = cv;
	// 	for(int i = 0; i < curr.size(); ++i){
	// 		if (i < pos){
	// 			if (vals[i] != cv){
	// 				ignore[curr[i]] = true;
	// 			}
	// 		}
	// 		else if (i == pos){
	// 			ignore[curr[i]] = true;
	// 		}
	// 		else{
	// 			if (vals[i - 1] != cv){
	// 				ignore[curr[i]] = true;
	// 			}

	// 		}
	// 	}
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
    // cin>>t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}