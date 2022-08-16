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


bool vis[maxn];
vi ans;
void pre(){
	int n=0;
	int sm=1;
	while(n<1e4){
		bool f=0;
		for(int i=sm;i<MaxN;++i){
			if (f) break;
			if (vis[i]) continue;
			for(int j=i+1;j<MaxN;++j){
				if (vis[j]) continue;
				if (vis[i^j]) continue;
				// if (i>=64 && i<128){
				// 	trace(i,j,i^j);
				// }
				vis[i]=1;
				vis[j]=1;
				vis[i^j]=1;
				ans.pb(i);
				ans.pb(j);
				ans.pb(i^j);
				f=1;
				break;
			}
		}
		while(vis[sm]) ++sm;

		n+=3;
	}
}


int V[4]={0,2,3,1};
int fin(int n){
	int k=0;
	int val=1;


	while(4*val-1<n){
		val*=4;
		k+=2;
	}
	int lef=(n-(val)+1);
	int tot=(lef+2)/3;
	int a=val+(tot)-1;
	// trace(n,a,lef,tot,val,k);

	// trace(ans[n-1]);
	if ((n%3)==1){
		return a;
		// cout<<a<<endl;
		// return;
	}
	int A=(a-(a%4));

	int z=3;

	int a1=A/4;
	int mul=4;
	int b1=0;

	while(a1){
		int t=V[(a1&3)];
		b1^=(t*mul);
		mul*=4;
		a1/=4;
	}
	// trace(A,b1);




	int b,c;
	if ((a%4)==0){

		b=b1;
		c=a^b;
		// b=2*a;
		// c=3*a;

	}
	else if ((a%4)==1){
		b=b1+2;
		c=a^b;
	}
	else if ((a%4)==2){
		b=b1+3;
		c=a^b;
	}
	else{
		b=b1+1;
		c=a^b;
	}
	if ((n%3)==2){
		return b;
		// cout<<b<<endl;
	}
	else return c;	
}

void solve(){
	int n;
	cin>>n;

	if (n<=ans.size()){
		cout<<ans[n-1]<<endl;
		return;
	}
	cout<<fin(n)<<endl;

	



	// vector<int> ans;
	
	// trace(ans);
}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
   pre();
   // trace(ans);
   // trace(fin(41),ans[39],ans[40],ans[41]);

   For(i,1000){
   		// if (ans[i]!=fin(i+1)){
   		// 	trace(i);
   		// }
   		assert(ans[i]==fin(i+1));
   }
   // trace(ans);
    fio;
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}