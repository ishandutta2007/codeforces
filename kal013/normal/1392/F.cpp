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

/*/-----------------------------Code begins----------------------------------/*/

bool do_vec(vector<ll>& h){
	int n = h.size();
	vector<int> a(h.size(), 0);

	bool does = false;
	for(int i = 1; i < n; ++i){
		assert(h[i] >= h[i - 1]);
		if (h[i] >= h[i - 1] + 2){
			a[i] -= 1;
			a[i - 1] += 1;
			does = true;
		}
	}
	for(int i = 0; i < n; ++i){
		h[i] += a[i];
	}
	return does;

}
void brute(vector<ll>& h){
	int n = h.size();

	for(int i = 1; i < n; ++i){
		assert(h[i] >= h[i - 1]);
	}

	bool x = true;

	while(x){
		x = do_vec(h);
		// trace(h);
	}
}

void brute2(vector<ll>& h){
	if (h.size() == 1){
		return;
	}

	vector<ll> x(1 + all(h));
	brute2(x);
	int n = h.size();
	if (h[0] == x[0]){
		for(int i = 1; i < n; ++i){
			h[i] = x[i  - 1];
		}
		return;
	}
	trace(x);
	x.insert(x.begin(), x[0] - 1);

	int k = x[0];
	int it = n - 1;
	while(k > h[0]){

		if (it == 0 || x[it] > x[it - 1]){
			--x[it];
			--k;	
		}
		

		it = (it - 1 + n) % n;
	}

	for(int i = 0; i < n; ++i){
		h[i] = x[i];
	}	

}



const int N = 3e6 + 5;
int cnt[N];


#define int ll

void print(int l,int r,int prv){
	for(int i = r; i >= l; --i){
		assert(cnt[i] > 0);
		for(int k = 0; k < cnt[i]; ++k){
			cout << prv << " ";
		}
		++prv;
	}
	cout << endl;	
}
void solve(){
	int n;
	cin >> n;
	vector<ll> h(n);
	cin >> h;


	cnt[0] = 1;

	ll prv = h.back();
	ll l = 0, r = 0;

	set<int> doub;
	for(int i = n - 2; i >= 0; --i){

		++cnt[r];

		ll dif = prv - h[i];

		if (dif == 0){
			if (cnt[r] > 1){
				doub.insert(r);
			}
			continue;
		}
		--prv;

		--dif;
		--cnt[r];
		++r;
		++cnt[r];
		ll req = n - i;

		while(doub.size() > 0 && dif > 0){
			auto it = *doub.rbegin();
			// trace(it, cnt[l], cnt[r], l, r);
			assert(cnt[it] > 1);
			--cnt[it];

			ll mv = r + 1 - it;
			if (mv <= dif){
				++r;
				++cnt[r];
				--prv;

				dif -= mv;
			}
			else{
				cnt[it + dif]++;
				assert(cnt[it + dif] > 1);
				doub.insert(it + dif);
				dif = 0;
			}

			
			if (cnt[it] == 1){
				doub.erase(it);
			}
		}

		// print(l, r, prv);

		// cout << "3efr" << endl;

		// cout << doub << endl;
		// cout << dif << " " << l << " " << r << endl;
		if (dif > 0){
			assert( (r - l + 1) == req);
			assert(doub.size() == 0);

			prv -= (dif) / (r - l + 1);
			dif %= (r - l + 1);

			if (dif == 0){
				continue;
			}



			assert(cnt[l] == 1 && cnt[r] == 1);
			++cnt[l + dif];
			--cnt[l];
			doub.insert(l + dif);

			++l;
			// if (cnt[l] == 0){
				// trace(l, dif, l + dif, r);
				// assert(cnt[l + dif] > 0);

			
		}

		// print(l, r, prv);


		// while((r - l + 1) < req && dif >= (r - l + 1)){
		// 	--cnt[l];
		// 	if (cnt[l] == 0){
		// 		++l;
		// 	}
		// 	++r;
		// 	++cnt[r];
		// 	dif -= (r - l + 1);
		// 	--prv;

		// 	print(l, r, prv);
		// }
		// if (dif < (r - l + 1)){
		// 	cnt[l + dif]++;
		// 	--cnt[l];
		// 	if (cnt[l] == 0)
		// 		++l;
		// 	dif = 0;
		// }
		// else{
		// 	prv -= (dif / req);
		// 	dif %= req;
		// 	++cnt[l + dif];
		// 	--cnt[l];
		// 	if (cnt[l] == 0)
		// 		++l;
		// 	dif = 0;

		// }

		// trace(dif,prv, i, l, r, cnt[l], cnt[r]);
	}


	// for(int i = r; i >= l; --i){
	// 	assert(cnt[i] > 0);
	// 	for(int k = 0; k < cnt[i]; ++k){
	// 		cout << prv << " ";
	// 	}
	// 	++prv;
	// }
	// cout << endl;
	print(l, r, prv);
	// vector<ll> c(all(h));
	// brute(h);


	

	// cout << h << endl;
	// brute2(c);

	// cout << c << endl;





}
#undef int
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    //cin >> t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}