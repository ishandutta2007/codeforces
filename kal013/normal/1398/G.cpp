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
    const static long long N = (1'000'000'000'000'000'000);
    if (T < 0){
        os << '-';
        T *= -1;
    }

    unsigned long long b = T%N;
    T /= N;
    if (T == 0)
        return os << b ;
    unsigned long long a = T % N;
    T /= N;
    if (T == 0){
        os << a;
        __int128 mul = 10;
        int cnt = 0;
        while( mul*b < N && cnt < 17){
            os << '0';
            mul *= 10;
            ++cnt;
        }
        return os << b;
    }
    os << ((long long) T);
    
     __int128 mul = 10;
      int cnt = 0;
    while( mul*a < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
    }
    os << a;
    mul = 10;
    cnt = 0;
    while( mul*b < N && cnt < 17){
        os << '0';
        mul *= 10;
        ++cnt;
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


//***remember to call precompute powers,set MAXN
#define ld double //*** double is much faster 
struct base{
	ld x,y;
	base(){x=y=0;}
	base(ld _x, ld _y){x = _x,y = _y;}
	base(ld _x){x = _x, y = 0;}
	void operator = (ld _x){x = _x,y = 0;}
	ld real(){return x;}
	ld imag(){return y;}
	base operator +(const base& b){return base(x+b.x,y+b.y);}
	void operator +=(const base& b){x+=b.x,y+=b.y;}
	base operator *(const base& b){return base(x*b.x - y*b.y,x*b.y+y*b.x);}
	void operator *=(const base& b){ld p = x*b.x - y*b.y, q = x*b.y+y*b.x; x = p, y = q;}
	void operator /=(ld k){x/=k,y/=k;}
	base operator -(const base& b){return base(x - b.x,y - b.y);}
	void operator -=(const base& b){x-=b.x,y-= b.y;}
	base conj(){ return base(x, -y);}
	base operator / (ld k) { return base(x / k, y / k);}
	void Print(){ cerr << x <<  " + " << y << "i\n";}
};
const double PI = 2.0*acos(0.0);
const int MAXN = 21;
const int maxn = (1<<MAXN);
base W[maxn],invW[maxn], P1[maxn], Q1[maxn];
void precompute_powers(){
	for(int i = 0;i<maxn/2;i++){
		double ang = (2*PI*i)/maxn; 
		ld _cos = cos(ang), _sin = sin(ang);
		W[i]=base(_cos,_sin);invW[i]=base(_cos,-_sin);
}}
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	for(int i=1, j=0; i<n; ++i){ int bit = n >> 1;
		for (; j>=bit; bit>>=1)j-=bit;
		j += bit; if(i<j)swap (a[i], a[j]); }
	for (int len=2; len<=n; len<<=1) {
		for (int i=0; i<n; i+=len) {
			int ind = 0,add = maxn/len;
			for (int j=0; j<len/2; ++j){
				base u = a[i+j],  v = (a[i+j+len/2] * (invert?invW[ind]:W[ind]));
				a[i+j] = (u + v); a[i+j+len/2] = (u - v);
				ind += add; } } }
	if (invert)for(int i=0; i<n; ++i)a[i]/=n;
 }
// Make functions add, sub , mul,powr, inv
vector<long long> mul(vi a, vi b){
	int n1 = a.size(),n2 = b.size();int n = 1;
	int final_size = a.size() + b.size() - 1;
	while(n<final_size) n<<=1; vector<base> P(n),Q(n);


 	for(int i=0;i<n1;i++){
 		P[i]=base(a[i],0);
 	}
 	for(int i=0;i<n2;i++) {
 		Q[i]=base(b[i],0);
 	}
	fft(P, 0); fft(Q, 0); 


	base A1, A2, B1, B2, X, Y;
	for(int i = 0; i < n; i++){
		P[i] *= Q[i];	
	}
	// for(int i = 0; i < n; i++)P[i]=P1[i],Q[i]=Q1[i];
	fft(P, 1); 
	// fft(Q, 1);
	vector<long long> ans(final_size);
	for(int i = 0; i < final_size; i++){
		ll x = (ll)(P[i].real() + 0.5);
		// ll y = (ll)(P[i].imag() + 0.5) % mod;
		// ll z = (ll)(Q[i].real() + 0.5);
		ans[i] = (x != 0) ? 1: 0;
	} 

	return ans;}
/*/-----------------------------Code begins----------------------------------/*/

const int offset =2e5 +  10;

const int N = 2e6 + 10;
int cnt[N], pos[N];
void solve(){

	int n, x, y;
	cin >> n >> x >> y;

	memset(pos, -1, sizeof(pos));
	vector<int> a(n + 1);

	cin >> a;


	vector<int> p1(x + offset + 1,0), p2(offset + 1, 0);

	for(auto e: a){
		p1[offset + e]++;
		p2[offset - e]++;
	}
	vector<long long> p3 = mul(p1, p2);
	for(int i = 2*offset + 1; i < p3.size(); ++i){
		int j = i - 2*offset;
		cnt[2*j + 2*y] += p3[i];

	}

	for(int i = N - 1; i >= 1; --i){
		if (cnt[i] > 0){
			for(int j = i; j < N ; j += i){
				pos[j] = max(pos[j], i);
			}	
		}
		
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; ++i){
		int l;
		cin >> l;
		cout << pos[l] << " ";
	}
	cout << "\n";


}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    precompute_powers();
    //cin >> t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}