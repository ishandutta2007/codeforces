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

const int N = 200;
const int M = 1e6 + 10;
ll dp[N][11];

string f[N][11];


inline int f_sum(int n){
	return ((n*(n+1)))/2;
}
int cnt[M];
void pre(){
	for(int i = 0 ; i < N; ++i){
		for(int z = 0; z< 11; ++z){
			dp[i][z] = -1;
			f[i][z] = "";
		}
	}
	cnt[0] = 0;
	for(int i = 1; i < M; ++i){
		cnt[i] = (i%10) + cnt[i/10];
	}


	for(int i = 0; i < M; ++i){
		ll c_sum = 0;
		for(int k = 0; k <= 9; ++k){
			if (i+k >= M) break;
			c_sum += cnt[i+k];

			if (c_sum < N && dp[c_sum][k] == -1){

				dp[c_sum][k] = i;
			}
		}

		
	}
}

string ans(int n,int k){
	if (dp[n][k] != -1){
		return to_string(dp[n][k]);
	}
	if (f[n][k].size() > 0){
		return f[n][k];
	}

	if (k == 0){
		string res;
		while (n > 9){
			res += '9';
			n -= 9;
		}
		res +=  (char (n + '0'));

		reverse(all(res));

		f[n][k] = res;
		return res;
	}

	if (k == 8){
		if ((n%9) != 0){
			f[n][k] = "-1";
			return f[n][k];
		}
	}

	if (k == 2){
		if ((n%3) != 0){
			f[n][k] = "-1";
			return f[n][k];
		}
	}

	if (k == 5){
		if ((n%3) != 0){
			f[n][k] = "-1";
			return f[n][k];
		}
	}


	if (k == 1){
		pair<int,string> cans = {1000000000,"-1"};

		for(int cnt_9 = 0; cnt_9 < cans.first; ++cnt_9){
			ll su = cnt_9 * 9 + 1;
			if (su > n){
				break;
			}
			ll reach = n - su;

			if (reach & 1){
				continue;
			}

			string res = "";
			for(int v = 0; v < cnt_9; ++v) {
				res += '9';
			}
			reach /= 2;

			if (reach < 9 && reach > 0){
				res += (char (reach + '0'));
			}
			else{
				reach -= 8;
				res += '8';

			}
			while (reach > 0){
				int z = min(reach,9ll);
				res += (char (z + '0'));
				reach -= z;
			}
			reverse(all(res));
			cans = min({res.size(),res},cans);
		}
		f[n][k] = cans.second;
		return f[n][k];
	}
	bool any = false;
	for(int digit_sum = 0; digit_sum <= n; ++digit_sum){
		int md = digit_sum * (k+1) +  ((k*(k+1))/2);
		md %= 9;

		if (md == (n%9)){
			any = true;
			break;
		}
	}
	if (!any){
		f[n][k] = "-1";
		return f[n][k];

	}


	trace("hello");

	pair<int,string> cans = {1000000000,"-1"};

	for(int cnt_9 = 1; cnt_9 < cans.first; ++cnt_9){
		ll su = cnt_9 * 9 + 1;
		if (su > n){
			break;
		}
		for(int z = 1; z<=k; ++z){
			ll su = (z*cnt_9*9) + f_sum(k+1-z) - (z*(z-1))/2;

			trace(cnt_9,z,su,k);
			if (su > n) continue;
			ll reach = n - su;

			if ((reach%(k+1)) != 0){
				continue;
			}

			reach /= (k+1);
			string res = "";
			res += (char)((10 - z) + '0');
			for(int v = 0; v < cnt_9 - 1; ++v) {
				res += '9';
			}
			if (reach < 9 && reach > 0){
				res += (char (reach + '0'));
				reach = 0;
			}
			else{
				reach -= 8;
				res += '8';

			}

			while (reach > 0){
				int z = min(reach,9ll);
				res += (char (z + '0'));
				reach -= z;
			}
			reverse(all(res));
			cans = min({res.size(),res},cans);
			trace(cans,cnt_9,z);
		}
		

		
	}

	for(int z = 0; z + k <=9; ++z){
		ll vs = f_sum(z+k) - f_sum(z-1);
		if ( n < vs) break;

		ll reach = n - vs;

		if ((reach%(k+1)) != 0){
			continue;
		}
		string t ="";
		t += ((char)(z + '0'));
		reach /= (k+1);
		while (reach > 0){
			int z = min(reach,9ll);
			t += (char)(z + '0');
			reach -=z;

		}
		reverse(all(t));

		cans = min({t.size(),t},cans);
	}
	f[n][k]= cans.second;
	return f[n][k];
}




void solve(){
    ll n,k;
    cin>>n>>k;

    ll m_s = k*(k+1);
    m_s /=2;
    if (n < m_s){
    	cout<<-1<<endl;
    	return;
    }
    cout<<ans(n,k)<<endl;
}

int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    pre();
    
    cin>>t;

    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}