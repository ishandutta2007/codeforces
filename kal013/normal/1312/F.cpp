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

const int N=1e4;

int dp[N][6][6][6][3]; // state n (x,y,z) 0,1,2
bool vis[N][6][6][6][3];

int state(int n,int x,int y,int z,int k){
	if (vis[n][x][y][z][k]) return dp[n][x][y][z][k];

	vis[n][x][y][z][k]=true;
	int cur=0;

	if (n==0){
		cur=0;
		dp[n][x][y][z][k]=cur;

		return 0;
	}
	set<int> C;

	C.insert(state(max(n-x,0ll),x,y,z,0));
	if (k!=1) C.insert(state(max(n-y,0ll),x,y,z,1));
	if (k!=2)  C.insert(state(max(n-z,0ll),x,y,z,2));


	while(C.find(cur)!=C.end()) ++cur;
	dp[n][x][y][z][k]=cur;
	return cur;	
}


int period[6][6][6][3];


int getper(int x,int y,int z,int k){
	if (period[x][y][z][k]!=0){
		return period[x][y][z][k];
	}
	int ans=0;
	for(int stp=1;;++stp){
		bool f=1;
		for(int cu=200;cu<N;++cu){
			if (state(cu,x,y,z,k)!=state(cu-stp,x,y,z,k)){
				// trace(stp,k,state(k,x,y,z,0),state(k-stp,x,y,z,0));
				f=0;
				break;
			}
		}
		if (f){
			ans=stp;
			break;
		}
	}
	period[x][y][z][k]=ans;
	return ans;

}


void pre(){
	// for(int i=100;i<=300;++i){
		// trace(1,2,3,i,state(1,2,3,i,0));
	// }
	// for(int x=1;x<=5;++x){
	// 	for(int y=1;y<=5;++y){
	// 		for(int z=1;z<=5;++z){
	// 			for(int k=0;k<=2;++k){
	// 				trace(x,y,z,k,getper(x,y,z,k));
	// 			}
	// 		}
	// 	}
	// }

}




inline int getgrundyn(int n,int x,int y,int z,int k){
	if (n<N){
		return state(n,x,y,z,k);
	}
	int tp=getper(x,y,z,k);
	n=(n%(tp))+tp*10;
	return getgrundyn(n,x,y,z,k);
}

void solve(){
	int n,x,y,z;
	cin>>n>>x>>y>>z;

	int cur=0;
	vi A(n);
	For(i,n){
		cin>>A[i];
		cur^=getgrundyn(A[i],x,y,z,0);

	}
	if (cur){
		int ways=0;

		For(i,n){
			int t1=getgrundyn(A[i],x,y,z,0);
			cur^=t1;
			int v1=getgrundyn(max(A[i]-x,0ll),x,y,z,0);
			int v2=getgrundyn(max(A[i]-y,0ll),x,y,z,1);
			int v3=getgrundyn(max(A[i]-z,0ll),x,y,z,2);
			if (cur==v1) ++ways;
			if (cur==v2) ++ways;
			if (cur==v3) ++ways;
			cur^=t1;
		}


		cout<<ways<<endl;
	}
	else{
		cout<<0<<endl;
	}
	// for(int i=1;i<=100;++i){
		// trace(i,state(i,1,2,3,0));
	// }
	// trace(getper(1,2,3));
	
}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    fio;
    pre();
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}