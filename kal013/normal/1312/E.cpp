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
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define d5(a,b,c,d,e) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<endl
#define d6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<endl
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

const int N=600;
int arr[N];

int dp[N][N];

int suff[N];

bool isreduc(int i,int j){
	if (i==j) return true;
	assert(i<j);

	vi tp;
	for(int k=i;k<=j;++k){
		tp.pb(arr[k]);
	}



}

inline int getreduce(int i,int j){
	vi tmp;
	for(int z=i;z<=j;++z){
		tmp.pb(arr[z]);
	}
	sort(all(tmp));
	// trace(tmp);
	int cval=tmp[0];
	int cnt=1;
	for(int z=1;z<tmp.size();){
		while(z<tmp.size() && tmp[z]==cval){
			++cnt;++z;
		}
		while(z<tmp.size() && cval<tmp[z]){
			if (((cnt)%2)!=0){
				return -1;
			}
			cnt>>=1;
			++cval;
		}
	}
	while(cnt>1){
		if (((cnt)%2)!=0){
			return -1;
		}
		++cval;
		cnt>>=1;
	}
	return cval;
}


inline int state(int i,int j){
	if (dp[i][j]>0) return dp[i][j];
	if (i==j) {
		dp[i][j]=1;
		return 1;
	}
	if (i+1==j){
		dp[i][j]=1+(arr[i]!=arr[i+1]);
		return dp[i][j];
	}


	// pii ans={j-i+1,INF};
	// suff[j]=arr[j];
	// for(int z=j-1;z>=i;--z){
	// 	suff[z]=max(suff[z])
	// }

	// int mx1=arr[i];
	// for(int k=i;k<j;++k){
	// 	int val=state(i,k)+state(k+1,j);

	// 	mx1=max(mx1,arr[i])
	// }



	// if (isreduc(i,j)){
	// 	dp[i][j]=1;
	// 	return 1;
	// }
	dp[i][j]=(j-i+1);
	for(int k=i;k<j;++k){
		int val=state(i,k)+state(k+1,j);

		if (val==2){
			int x1=getreduce(i,k);
			if (x1!=-1){
				int x2=getreduce(k+1,j);
				if (x1==x2){
					dp[i][j]=1;
				}
			}
		}
		dp[i][j]=min(dp[i][j],val);
		if (dp[i][j]==1) break;
	}
	return dp[i][j];


}

void solve(){
	int n;
	cin>>n;
	Rep(i,n) cin>>arr[i];
	cout<<state(1,n)<<endl;
	// cout<<getreduce(1,4)<<endl;
}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
   
    fio;
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}