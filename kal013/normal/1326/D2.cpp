/*/ Author: kal013 /*/
//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long
#define ll long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<(int)n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,n) for(int i=1;i<=n;++i)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(v) (v).begin(),(v).end()
#define sz(v) (v).size()

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
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
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
    #define trace(...)
#endif
const int maxn=1e6+100;
const int MaxN=1e5+100;
const int mod=1e9+7;
#ifdef int
const int INF=1e16;
#else
const int INF=1e9;
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// erase,insert same as normal set
#endif

inline int fast_expo(int base,int power,int modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    // int tmp=ans;
    return ans;
}
inline int inv(int base,int modulo=mod){
    return fast_expo(base,modulo-2,modulo);
}


/*/-----------------------------Code begins----------------------------------/*/
#define vll vector<ll>


vll manacher_odd(string s){
	ll n = s.length(); vll d1(n);
	for(ll i=0,l=0,r=-1; i<n; i++){ d1[i] = 1;
		if(i <= r)
			d1[i]=min(r-i+1,d1[l+r-i]); // use prev val
		while(i+d1[i]<n && i-d1[i]>=0 && s[i+d1[i]]==s[i-d1[i]]) d1[i]++; // trivial matching
		if(r<i+d1[i]-1)l=i-d1[i]+1,r=i+d1[i]-1;//upt r
	} return d1; }
// takes string s and returns vector of lengths of even length ... | (it's centered around the right middle char, bb is centered around the later 'b')
vll manacher_even(string s){ ll n=s.length(); vll d2(n);
	for(ll i=0,l=0,r=-1;i<n;i++){ d2[i]=0;
		if(i <= r) d2[i] = min(r-i+1,d2[l+r+1-i]);
		while(i+d2[i]<n && i-d2[i]-1>=0 && s[i+d2[i]]==s[i-d2[i]-1])d2[i]++;
		if(d2[i]>0&&r<i+d2[i]-1)l=i-d2[i], r=i+d2[i]-1;
	} return d2; }

bool ispal(string x){
	int n=x.size();
	for(int i=0;2*i<=n;++i){
		if (x[i]!=x[n-1-i]){
			return false;
		}
	}
	return true;
}


string getmx(string z){
	int n=z.size();
	int lp=0,rp=n;
	for(int i=0;2*i<=(n);++i){
		if (z[i]!=z[n-1-i]) break;
		++lp;
		--rp;
	}

	vll v1=manacher_odd(z);
	vll v2=manacher_even(z);

	int mxl=lp;
	for(int i=lp;2*i<lp+rp;++i){
		int sub=v1[i]-1;
		int lef=i-lp;
		if (sub>=lef){
			mxl=2*i-lp;
			// trace(i,mxl,v1[i]);
		}

	}
	// trace(mxl,v1,v2,z,lp,rp);
	string ans1=z.substr(0,mxl+1)+z.substr(rp);
	int mxr=-1;
	for(int i=lp+1;2*i<lp+rp+1;++i){
		int sub=v2[i];
		int len=(i-lp);
		if (sub>=len){
			mxr=2*i-1-lp;
		}
	}
	if (mxr<=mxl) return ans1;
	return z.substr(0,mxr+1)+z.substr(rp);

}


void solve(){
	string z;
	cin>>z;

	int n=z.size();
	if (ispal(z)){
		cout<<z<<endl;
		return;
	}

	string k=getmx(z);
	reverse(all(z));
	string j=getmx(z);
	// trace(k,j,z);
	if (j.size()>k.size()) cout<<j<<endl;
	else cout<<k<<endl;
	// int lp=0,rp=n;
	// for(int i=0;2*i<=(n);++i){
	// 	if (z[i]!=z[n-1-i]) break;
	// 	++lp;
	// 	--rp;
	// }

	// vll v1=manacher_odd(z);
	// vll v2=manacher_even(z);

	// int mxl=lp;
	// for(int i=lp;2*i<lp+rp;++i){
	// 	int sub=v1[i]/2;
	// 	int lef=i-lp;
	// 	if (sub>=lef){
	// 		mxl=2*i-lp;
	// 		trace(i,mxl,v1[i]);
	// 	}

	// }
	// string ans1=z.substr(0,mxl+1)+z.substr(rp);



}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
   
    fio;
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}