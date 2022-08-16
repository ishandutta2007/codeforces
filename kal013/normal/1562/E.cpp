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
struct suffix_array{
    // Karkkainen implementation from paper https://www.cs.helsinki.fi/u/tpkarkka/publications/icalp03.pdf
    vector<int> p,cnt,s,lcp;
    int n;
    int alphabet;
    char start;
    suffix_array(int a=256,char st='a'): alphabet(a),start(st){}

    inline bool leq(int a1, int a2, int b1, int b2) {return (a1 < b1 || (a1 == b1 && a2 <= b2));}
    inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3)));}

    void radix(int* A,int* B,int* R,int N,int K){
        int* C=new int[K+1];
        for (int i = 0; i <= K; ++i) C[i] = 0;
        for (int i = 0; i < N; ++i) ++C[R[A[i]]]; 
        for (int i = 0, sum = 0; i <= K; ++i)  {int t = C[i]; C[i] = sum; sum += t;}
        for (int i = 0; i < N; i++) B[C[R[A[i]]]++] = A[i]; 
        delete [] C;
    }

    void suffixArray(int* s, int* SA, int N, int K) {
        int n0=(N+2)/3, n1=(N+1)/3, n2=N/3, n02=n0+n2;
        int* s12 = new int[n02 + 3]; s12[n02]= s12[n02+1]= s12[n02+2]=0;
        int* SA12 = new int[n02 + 3]; SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
        int* s0 = new int[n0];
        int* SA0 = new int[n0];
        for (int i=0, j=0; i < N+(n0-n1); i++) if (i%3 != 0) s12[j++] = i;
        radix(s12 , SA12, s+2, n02, K);
        radix(SA12, s12 , s+1, n02, K);
        radix(s12 , SA12, s , n02, K);
        int name = 0, c0 = -1, c1 = -1, c2 = -1;
        for (int i = 0; i < n02; i++) {
            if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2)
            {name++; c0 = s[SA12[i]]; c1 = s[SA12[i]+1]; c2 = s[SA12[i]+2]; }
            if (SA12[i] % 3 == 1) { s12[SA12[i]/3] = name; } 
            else {s12[SA12[i]/3 + n0] = name; }
        }
        if (name < n02) {
            suffixArray(s12, SA12, n02, name);
            for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
        } 
        else for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
        for (int i=0, j=0; i < n02; i++) if (SA12[i] < n0) s0[j++] = 3*SA12[i];
        radix(s0, SA0, s, n0, K);
        for (int p=0, t=n0-n1, k=0; k < N; k++) {
            #define GetI() (SA12[t] < n0 ? SA12[t]*3+1: (SA12[t] - n0) * 3 + 2)
            int i = GetI();
            int j = SA0[p]; 
            if (SA12[t] < n0 ?leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0])){
                SA[k] = i; t++;
                if (t == n02) for (k++; p < n0; p++, k++) SA[k] = SA0[p];
            } 
            else {
                SA[k] = j; p++;
                if (p == n0) for (k++; t < n02; t++, k++) SA[k] = GetI();
            }

        }
        #undef GetI
        delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
    }
    void build(string t){
        n=t.size();
        int* S=new int[n+3];
        s.resize(n+1);
        for(int i=0;i<n;++i) {S[i]=(int)(t[i]-start)+1;s[i]=S[i];}
        for(int i=n;i<=n+2;++i) S[i]=0;
        int* P=new int[n+3];
        suffixArray(S,P,n,alphabet);
        ++n;
        p.resize(n);
        cnt.assign(max(alphabet,n),0);
        p[0]=n-1;
        for(int i=1;i<n;++i) p[i]=P[i-1];
        delete [] S; delete [] P;
    }
    void prefix(){
        for(int i = 0; i < n; ++i) cnt[p[i]]=i;
        lcp.resize(n);
        int len=0;
        for(int i = 0; i < n; ++i){
            if (cnt[i]==n-1) {len=0;continue;}
            int j=p[cnt[i]+1];
            while (i+len<n && j+len<n && s[i+len]==s[j+len])++len;
            lcp[cnt[i]]=len;
            if (len) --len;
        }
    }
};

/*/-----------------------------Code begins----------------------------------/*/

const int N = 5005;
int lcp[N][N];




const int mlog = 20;



template< typename T, const int M , const T& (*Op)(const T& ,const  T&) = std::min<T> >
struct RMQ{
    // Tested : https://www.spoj.com/problems/RMQSQ/
    int offset;
    vector<T> rmq[M];
    static vector<int> log_2;
    void clear(){
        for(int i = 0 ; i < M ;++i) rmq[i].clear();
    }
    void init(vector<T>& V,int off = 0){
        offset = off;
        if (log_2.size() == 0) {log_2.push_back(0);log_2.push_back(0);}

        int n = V.size() - off;
        for(int i = 0; i < M; ++i){
            rmq[i].resize(n);
        }
        for(int i = 0; i < n; ++i){
            rmq[0][i] = V[i + off];
        }
        for(int j = 1; j < M; ++j){
            int powr = (1 << (j-1));
            for(int i = 0 ; i < n; ++i){
                if (i + powr >= n){
                    rmq[j][i] = rmq[j-1][i];
                }
                else{
                    rmq[j][i] = Op(rmq[j-1][i],rmq[j-1][i + powr]);
                }
            }
        }

        if (log_2.size() <= n){
            int k = log_2.size();
            log_2.reserve( n + 1);
            for(int i = k; i <= n; ++i){
                log_2.push_back(log_2[i / 2] + 1);
            }
        }
    }
    void init(T arr[], int N,int off = 0){
        offset = off;
        if (log_2.size() == 0) {log_2.push_back(0);log_2.push_back(0);}

        int n = N;
        for(int i = 0; i < M; ++i){
            rmq[i].resize(n);
        }
        for(int i = 0; i < n; ++i){
            rmq[0][i] = arr[i + off];
        }
        for(int j = 1; j < M; ++j){
            int powr = (1 << (j-1));
            for(int i = 0 ; i < n; ++i){
                if (i + powr >= n){
                    rmq[j][i] = rmq[j-1][i];
                }
                else{
                    rmq[j][i] = Op(rmq[j-1][i],rmq[j-1][i + powr]);
                }
            }
        }

        if (log_2.size() <= n){
            int k = log_2.size();
            log_2.reserve( n + 1);
            for(int i = k; i <= n; ++i){
                log_2.push_back(log_2[i / 2] + 1);
            }
        }
        assert(M > log_2[n]);
    }
    T query(int l,int r){
        assert(l <= r);
        l -= offset;
        r -= offset;
        int dist = log_2[r - l + 1];
        return Op(rmq[dist][l] , rmq[dist][r - (1ll << dist) + 1]);
    }


};


template<typename T, const int M , const T& (*Op)(const T& ,const  T&)  >
vector<int> RMQ<T,M,Op>::log_2 ;


// RMQ<int,13,std::min> rmq;


void solve(){
	int n;
	string s;
	cin >> n >> s;
	if (n == 1){
		cout << 1 << endl;
		return;
	}
	// n = 5000;
	// s = string(n, 'a' + random_long(0, 25));
	// for(int i = 0; i < n; ++i){
		// s[i] = ('a' + random_long(0, 25));
	// }
	suffix_array device;
	device.build(s);
	device.prefix();
	// vector<int> inv_pos(n);
	// for(int i = 1; i <= n; ++i){
	// 	inv_pos[device.p[i]] = i;
	// }
	// rmq.init(device.lcp);

	// for(int i = 0; i < n; ++i){
	// 	int inv_p = inv_pos[i];
	// 	lcp[i][i] = n - i;
	// 	for(int j = i + 1; j < n; ++j){
	// 		lcp[i][j] = rmq.query(min(inv_p, inv_pos[j]), max(inv_p, inv_pos[j]) - 1);
	// 	}
	// }
	for(int i = 1; i <= n; ++i){
		int pos = device.p[i];
		// assert (0 <= pos && pos < n);
		int val = n - pos;
		for(int j = i; j <= n; ++j){
			int pos2 = device.p[j];
			lcp[pos][pos2] = val;
			lcp[pos2][pos] = val;
			if (j < n)
				val = min(val, device.lcp[j]);
		}
	}

	auto cmp = [&] (const array<int,2>& L, const array<int, 2>& R){
		// int l1 = inv_pos[L[0]], r1 = inv_pos[R[0]];
		int len = lcp[L[0]][R[0]];
		// int len = (l1 == r1) ? (n - L[0]) : rmq.query(min(l1, r1), max(l1, r1) - 1);
		// int len = 0;
		int len1 = L[1] - L[0] + 1, len2 = R[1] - R[0] + 1;
		if (min(len1, len2) <= len){
			return len1 < len2;
		}
		return (s[L[0] + len] < s[R[0] + len]);
	};

	vector<array<int, 2>> lcs;
	lcs.reserve((n * (n + 1)) >> 1);

	for(int i = 0; i < n; ++i){
		int p_it = 0;
		for(int j = i; j < n; ++j){
			array<int, 2> X = {i, j};
			auto it = lower_bound(lcs.begin() + p_it, lcs.end(), X, cmp) - lcs.begin();
			p_it = it + 1;
			if (it == lcs.size()){
				lcs.push_back(X);
			}
			else{
				lcs[it] = X;
			}
		}
	}
	cout << lcs.size() << endl;
}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}