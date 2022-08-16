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
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

/*/---------------------------Defines----------------------/*/
#define ll long long
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()
#define ld long double
/*/-----------------------Modular Arithmetic---------------/*/
const int mod = 1e9 + 7;
ld INF = 1e100;
ld EPS = 1e-9;
inline bool eq(ld a,ld b){return fabs(a-b)<EPS;}
inline bool lt(ld a,ld b){return a+EPS<b;}
inline bool gt(ld a,ld b){return a>b+EPS;}
inline bool le(ld a,ld b){return lt(a,b)||eq(a,b);}
inline bool ge(ld a,ld b){return gt(a,b)||eq(a,b);}
// struct pt{
// 		#define F1 ld
// 		#define F2 ld
// 		#define F3 ld
// 		F1 x,y; pt() {};
// 		pt(F1 _x): x(_x),y((F1)(0)){};
// 		pt(F1 _x, F1 _y): x(_x),y(_y){};
// 		pt operator + (const pt &p) const {return pt(x+p.x,y+p.y);}
// 		pt operator - (const pt &p) const {return pt(x-p.x,y-p.y);}
// 		F2 operator * (const pt &p) const {return x*p.x+y*p.y;}
// 		F2 operator ^ (const pt &p) const {return x*p.y-y*p.x;}
// 		pt operator * (const F3 c) const {return pt(x*c,y*c);}
// 		pt operator / (const F3 c) const {return pt(x/c,y/c);}
// 		pt operator += (const pt &p) {this->x+=p.x;this->y+=p.y;return *this;}
// 		pt operator -= (const pt &p) {this->x-=p.x;this->y-=p.y;return *this;}
// 		pt operator *= (const F3 c) {this->x*=c;this->y*=c; return *this;}
// 		pt operator /= (const F3 c) {this->x/=c;this->y/=c;return *this;}
// 		// COMPARES y first
// 		bool operator < (const pt &p) const{ return lt(y,p.y)||(eq(y,p.y)&&lt(x,p.x));}
// 		inline bool operator == (const pt &r) const {return (eq(y,r.y) && eq(x,r.x));}
// 		bool operator > (const pt &p) const{ return p<pt(x,y);}
// 		inline bool operator <= (const pt &r) const {return !(*this>r);}
// 		inline bool operator >= (const pt &r) const {return !(*this<r);}
// 		inline bool operator != (const pt &r) const {return !(*this==r);}
// 		friend istream& operator >> (istream& is, pt& p){return is>>p.x>>p.y;}
// 		friend ostream& operator << (ostream& os, const pt& p) {return os<<"("<<p.x<<","<<p.y<<")";}
// };
// ld dot(pt p,pt q) {return p.x*q.x+p.y*q.y;}
// ld dist2(pt p, pt q) {return dot(p-q,p-q);}
// ld dist(pt p,pt q) {return sqrt(dist2(p,q));}
// ld norm2(pt p) {return dot(p,p);}
// ld norm(pt p) {return sqrt(norm2(p));}
// ld cross(pt p, pt q) { return p.x*q.y-p.y*q.x;}
/*/-----------------------------Code begins----------------------------------/*/

template<typename T>
T cross(const array<T, 2>& p, const array<T,2>& q){
	return (p[0] * q[1] - p[1] * q[0]);
}
template<typename T>
T doubleComputeSignedArea(const vector<array<T,2>> &p) {
	long long ans=0; 
	for(int i = 0; i < p.size(); i++) {
		int j = (i+1) % p.size();
		ans += cross(p[i],p[j]);
	} 
	return ans;
}

template<typename T>
struct Data{
	array<T, 2> p;
	T area;
	int mask;
	friend ostream& operator << (ostream& os, const Data<T>& D) {return os<<"( {"<<D.p[0]<<", "<<D.p[1]<<"} " << D.area << " )";}

};


template<typename T>
Data<T> ComputeCentroid(const vector<array<T,2>> &p) {
	array<T,2> c = {0,0};
	T scale =  3 * doubleComputeSignedArea(p);

	// if(p.empty())return inf;//empty vector
	// if(eq(scale,0)) return inf;//all points on straight line
	for (int i = 0; i < p.size(); i++){

		int j = (i+1) % p.size();

		T area = cross(p[i], p[j]);
		for(int k = 0; k < 2; ++k){
			c[k] = c[k] + (p[i][k] + p[j][k]) * area;
		}
		// c = c + (p[i] + p[j])*cross(p[i],p[j]);
	}
	return {c , scale, -1};
}


void solve(){
    // vector<array<long long,2>> U = {{0, 0}, {1,1}, {2, 0}, {3, 1}, {4, 2}, {5, 1}, {6, 0}};
    int n;
    cin >> n;
    long double x, y;
    cin >> x >> y;

    int K = n >> 1;
    // int K = n;
    assert(2 * K == n);


    auto is_correct = [&] (int x, int k, bool reverse){
    	if (reverse){
    		int suf = 0;
    		for(int i = k - 1; i >= 0; --i){
    			if (x & (1 << i)){
    				++suf;
    			}
    			else
    				--suf;

    			if (suf < 0)
    				return false;
    		}
    		return true;
    	}

    	int pref = 0;
    	for(int i = 0; i < k; ++i){
    		if (x & (1 << i))
    			--pref;
    		else
    			++pref;

    		if (pref < 0)
    			return false;

    	}
    	return true;
    };


    auto get_vec = [&] (int x, int k, int start){
    	vector<array<long long, 2>> ans;
    	if (start == 0){
    		ans.push_back({0, 0});
    		int y = 0;
    		for(int i = 0; i < k; ++i){
    			if (x & (1 << i)){
    				--y;
    			}
    			else{
    				++y;
    			}
				ans.push_back({i + 1, y});	
    		}
    	}
    	else{
    		ans.push_back({start, 0});
    		int y = 0;
    		for(int i = k - 1; i >= 0; --i){
    			if (x & (1 << i)){
    				++y;
    			}
    			else{
    				--y;
    			}
				ans.push_back({start + i - k, y});	
    		}
    	}
    	return ans;
    };


    auto distance3 = [&] (const array<long double, 3>& A, const array<long double, 3>& B){
    	return (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]);
    };


    auto get_closest = [&] (const array<long double, 3>& A, const vector<array<long double,3>>& P){
    	assert(P.size() > 0);
    	auto it = lower_bound(P.begin(), P.end(), A);
    	int idx = it - P.begin();
    	array<long double, 3> ret = P[0];
    	long double dis = distance3(ret, A);

    	// if (A[2] == 72){
    	// 	trace(idx, dis, P[idx + 1], P[idx], P[idx - 1]);
    	// 	trace(max(idx - 3, 0));
    	// }
    	for(int i = max(idx - 3, 0); i < min(idx + 3, (int)P.size()); ++i){
    		long double cdis = distance3(P[i], A);
    		// if (A[2] == 72){
    		// 	trace(i, idx,A );
    		// }
    		if (lt(cdis, dis)){
    			dis = cdis;
    			ret = P[i];
    		}
    	}
    	return ret;
    };

    auto get_string = [&] (int x, int y,int K){
    	string ans;
    	if (x >= 0){
    		for(int i = 0; i < K; ++i){
	    		if (x & (1 << i)){
	    			ans += ')';
	    		}
	    		else{
	    			ans += '(';
	    		}
	    	}
    	}
    	
    	if (y >= 0){
    		for(int i = 0; i < K; ++i){
	    		if (y & (1 << i)){
	    			ans += ')';
	    		}
	    		else{
	    			ans += '(';
	    		}
	    	}
    	}
    	
    	return ans;
    };

    vector<Data<long long>> extr[20], revr[20];

    for(int i = 0; i < (1 << K); ++i){
    	if (is_correct(i, K, false)){
    		// if (i == 16311){
    		// 	trace(i);
    		// }
    		// trace(get_vec(i, K, 0));
    		vector<array<long long,2>> cur = get_vec(i, K, 0);
    		int num = cur.back()[1];
    		if (num != 0){
    			cur.push_back({K, 0});
    		}

    		Data<long long> centr = ComputeCentroid(cur);
    		// if (i == 72){
    		// 	trace(centr);
    		// }
    		centr.mask = i;
    		extr[num].push_back(centr);

    	}
    	if (is_correct(i, K, true)){
			vector<array<long long,2>> cur = get_vec(i, K, n);
			int num = cur.back()[1];

    		if (num != 0){
    			cur.push_back({K, 0});
    		}
			reverse(all(cur));
			// trace(cur);
    		Data<long long> centr = ComputeCentroid(cur);

    		// if (i == 16378){
    		// 	trace(centr);
    		// }
    		centr.mask = i;
    		// trace(centr, cur, i);
    		revr[num].push_back(centr);    		
    	}
    }
    

    vector<array<long double, 3>> cpr[20];
    long double dif = 0;
    pair<int,int> masks = {-1, -1};
    for(int i = 0; i <= K; ++i){
    	for(auto j: revr[i]){
    		array<long double, 3> addr = {x * j.area - j.p[0], y * j.area - j.p[1], j.mask};
    		if (j.mask == 16378){
    			// trace(addr, i);
    		}
    		cpr[i].push_back(addr);
    	}
    	sort(all(cpr[i]));


    	for(auto z: extr[i]){
    		array<long double, 3> findr = {z.p[0] - x * z.area, z.p[1] - y * z.area, z.mask};
    		// trace(findr, cpr[i], i, z.mask, get_vec(z.mask, K, 0));	


    		array<long double, 3> nxtr = get_closest(findr, cpr[i]);
    		if (z.mask == 72){
    			// trace(findr, nxtr, i);
    		}
    		// trace(findr, z, nxtr);
    		long double cdis = distance3(nxtr, findr);
    		// if (cdis < 5){
    		// 	trace(findr, nxtr);
    		// }
    		if (masks.first == -1 || lt(cdis, dif)){
    			dif = cdis;
    			masks = {z.mask, (int)(nxtr[2] + 0.5)};
    		}
    	}
    }

    // trace(masks, x, y);
    cout << get_string(masks.first, masks.second, K);

    // string u;
    // cin >> u;

    // int m1 = 0, m2 = 0;
    // for(int i = 0; i < K; ++i){
    // 	if (u[i] == ')'){
    // 		m1 |= (1 << i);
    // 	}
    // 	if (u[K + i] == ')'){
    // 		m2 |= (1 << i);
    // 	}
    // }
    // trace(masks);
    // trace(m1, m2);

    // trace(get_string(m1, -1, K));
    // trace(extr);
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