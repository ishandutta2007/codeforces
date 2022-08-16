/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 

/*/---------------------------IO(Debugging)----------------------/*/
template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<class T, size_t N> istream& operator >> (istream &is, array<T, N>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
istream& operator >> (istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){
    static queue<P> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.front() << " ", U.pop();
    return (out << "}");
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

/*/---------------------------RNG----------------------/*/
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int64_t random_long(long long l = LLONG_MIN,long long r = LLONG_MAX){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
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
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define endl "\n"
#define all(v) (v).begin(),(v).end()
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;

/*/-----------------------------Code begins----------------------------------/*/
const __float128 INF = 1e100;
void solve(){
    int n, k;
    cin >> n >> k;
    --k;
    vector<array<int, 3>> pts(n);

    auto is_collinear = [&] (const array<int, 3>& X, const array<int, 3>& Y, const	array<int, 3>& Z){
    	return (((Y[0] - X[0]) * 1LL * (Z[1] - X[1])) == ((Z[0] - X[0]) * 1LL * (Y[1] - X[1])));
    };

    auto distance_pt = [&] (const array<int, 3>& X, const array<int, 3>& Y){
    	long double x = X[0] - Y[0], y = X[1] - Y[1];
    	return sqrt(x * x + y * y);
    };

    auto calculate_dp = [&] (const vector<array<int, 3>>& P){
    	int m = P.size();


    	vector<vector<__float128>> dp(m, vector<__float128>(1 << m, INF));
    	int idx = -1;
    	for (int i = 0; i < m; ++i){
    		if (P[i][2] == k){
    			idx = i;
    			break;
    		}
    	}
    	assert (idx != -1);

	    dp[idx][1 << idx] = 0;

	    for(int i = 0; i < (1 << m); ++i){
	    	for(int j = 0; j < m; ++j){
	    		if (i & (1 << j)){
	    			int old = i ^ (1 << j);
	    			for(int k = 0; k < m; ++k){
	    				if (old & (1 << k)){
	    					dp[j][i] = min(dp[j][i], dp[k][old] + distance_pt(P[j], P[k]));
	    				}
	    			}
	    		}
	    	}
	    } 
	    __float128 ret = INF;
	    for(int i = 0; i < m; ++i){
	    	ret = min(ret, dp[i][(1 << m) - 1]);
	    }
	    return (long double)ret;
    };

    for(int i = 0; i < n; ++i){
    	cin >> pts[i][0] >> pts[i][1];
    	pts[i][2] = i; 
    }
    sort(all(pts));
    __float128 ans = INF;



    array<int, 3> other = {INT_MIN, INT_MIN, INT_MIN};

    {
    	if (n == 3){
    		other = pts.back();
    		pts.pop_back();
    	}
    	else{
    		array<int, 3> p1, p2;
    		if (is_collinear(pts[0], pts[1], pts[2])){
    			p1 = pts[0];
    			p2 = pts[1];
    		}
    		else if (is_collinear(pts[0], pts[1], pts[3])) {
    			p1 = pts[0];
    			p2 = pts[1];
    		}
    		else if (is_collinear(pts[0], pts[2], pts[3])){
    			p1 = pts[0];
    			p2 = pts[2];
    		}
    		else{
    			assert (is_collinear(pts[1], pts[2], pts[3]));
    			p1 = pts[1];
    			p2 = pts[2];
    		}
    		vector<array<int, 3>> nw;
    		for(auto e: pts){
    			if (is_collinear(p1, p2, e)){
    				nw.push_back(e);
    			}
    			else{
    				other = e;
    			}
    		}
    		swap(pts, nw);
    		assert (pts.size() == n - 1 && other[0] != INT_MIN);
    	}
    }
    sort(all(pts));
    vector<array<int, 3>> relevant; 
    int PAIRS = 0;
    {
    	if (other[2] == k){
    		relevant.push_back(other);
    		relevant.push_back(pts[0]);
    		relevant.push_back(pts.back());
    		ans = distance_pt(pts.back(), pts[0]) + min(distance_pt(other, pts[0]),distance_pt(other, pts.back()));
    	}
    	else{

    		int idx = -1;
    		for(int i = 0; i < pts.size(); ++i){
    			if (pts[i][2] == k){
    				idx = i;
    				break;
    			}
    		}

    		auto triangle_dist = [&] (const array<int, 3>& A, const array<int, 3>& B, const	array<int, 3>& C){
    			return distance_pt(B, C) + min(distance_pt(A, B), distance_pt(A, C));
    		};
    		assert (idx != -1);
    		ans = min(ans,(__float128) distance_pt(pts[0], pts[idx]) + distance_pt(pts[0], pts.back()) + distance_pt(pts.back(), other));
    		ans = min(ans, (__float128) distance_pt(pts.back(), pts[idx]) + distance_pt(pts[0], pts.back()) + distance_pt(pts[0], other));

    		ans = min(ans, (__float128) distance_pt(pts[idx], other) + triangle_dist(other, pts[0], pts.back()));
    		if (idx + 1 < pts.size()){
    			ans = min(ans, (__float128) distance_pt(pts[0], pts[idx]) + distance_pt(pts[0], other) + triangle_dist(other, pts[idx + 1], pts.back()));
    		}
    		if (idx > 0){
    			ans = min(ans, (__float128) distance_pt(pts.back(), pts[idx]) + distance_pt(pts.back(), other) + triangle_dist(other, pts[idx - 1], pts[0]));
    		}

    		for(int z = 1; z < pts.size(); ++z){
    			ans = min(ans, (__float128) distance_pt(pts[0], pts[idx]) + distance_pt(pts[0], pts.back()) + distance_pt(pts[z], other) + distance_pt(pts[z - 1], other) - distance_pt(pts[z], pts[z - 1]));
    			ans = min(ans, (__float128) distance_pt(pts.back(), pts[idx]) + distance_pt(pts[0], pts.back()) + distance_pt(pts[z], other) + distance_pt(pts[z - 1], other) - distance_pt(pts[z], pts[z - 1]));
    		}
    		// set<array<int, 3>> req = {pts[0], pts.back(), other};
    		// vector<pair<__float128, int>> tmp;
    		// for(int z = 1; z < pts.size(); ++z){
    		// 	tmp.push_back({distance_pt(other, pts[z]) + distance_pt(other, pts[z - 1]) - distance_pt(pts[z - 1], pts[z]), z});
    		// }
    		// sort(all(tmp)); reverse(all(tmp));

    		// for(int k = 0; k < PAIRS && tmp.size() > 0; ++k){
    		// 	auto X = tmp.back();
    		// 	tmp.pop_back();

    		// 	req.insert(pts[X.second]);
    		// 	req.insert(pts[X.second - 1]);
    		// }

    		// for(int z = 0; z < pts.size(); ++z){
    		// 	if (pts[z][2] == k){
    		// 		req.insert(pts[z]);
    		// 		if (z > 0)
    		// 			req.insert(pts[z - 1]);
    		// 		if (z + 1 < pts.size())
    		// 			req.insert(pts[z + 1]);
    		// 	}
    		// }


    		// for(auto e: req){
    		// 	relevant.push_back(e);
    		// }
    	}
    }
    // assert (relevant.size() >= 3 && relevant.size() <= 6 + 2 * PAIRS);

    // trace(relevant);
    // cout << calculate_dp(relevant) << endl;
    cout << (long double) ans << endl;

  //   {
	 //    pts.push_back(other);
  //   	trace(calculate_dp(pts));
		// pts.pop_back();    	
  //   }

}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}