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
// #define endl "\n"
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


void query(set<int>& x){
	cout<<"?"<<" ";
	for(auto e:x) cout<<e<<" ";
	cout<<endl;
}
void answer(int m){
	cout<<"!"<<" "<<m<<endl;
}
const int N=1000;
int A[N];
set<int> found;
void solve(){
	int n,k;
	cin>>n>>k;
	Rep(i,n){
		A[i]=-1;
	}
	if (k==1){
		answer(1);
		return;
	}

	set<int> cu;
	set<int> ex;
	Rep(i,k){
		cu.insert(i);
	}
	int last=-1;
	for(int i=k+1;i<=n+1;++i){
		query(cu);
		int x;
		cin>>x;
		cin>>A[x];
		last=x;
		found.insert(x);
		cu.erase(x);
		if (i<=n) cu.insert(i);
	}

	if (found.size()>=k){
		set<int> tp;

		for(auto e:found){
			if (tp.size()<k) tp.insert(e);
		}
		query(tp);
		int x,y;
		cin>>x;
		cin>>y;
		int m=0;
		for(auto e:tp){
			if (A[e]<=y) ++m;
		}
		answer(m);
		return;
	}
	set<int> tp;
	for(auto e:cu){
		tp.insert(e);
	}
	tp.insert(last);
	int cval=A[last];
	set<int> rem;

	for(auto e:found){
		if (e!=last) rem.insert(e);
	}
// 	trace(rem,k,found.size());
	while(found.size()<k){
// 		trace(found,k);
		int tmp=-1;
		for(auto e:tp){
			if (found.find(e)==found.end()){
				tmp=e;
				break;
			}
		}
		tp.erase(tmp);
		auto it=rem.begin();
		auto X=*it;
		rem.erase(it);
        rem.insert(tmp);
		bool les=(A[X]<A[last]);
		tp.insert(X);
		query(tp);
		int x,y;
		cin>>x>>y;
		last=x;
		
		found.insert(tmp);
		if (y<cval){
			if (les){
				A[tmp]=INF;
			}
			else{
				assert(0);
			}
		}
		else if (y==cval){
			if (les){
				A[tmp]=-1;				
			}
			else{
				A[tmp]=INF;
			}
		}
		else{
			if (les) assert(0);
			A[tmp]=-1;
		}
		cval=y;
	}
// 	trace(1);
	if (found.size()>=k){
		set<int> tp;

		for(auto e:found){
			if (tp.size()<k) tp.insert(e);
		}
		query(tp);
		int x,y;
		cin>>x;
		cin>>y;
		int m=0;
		for(auto e:tp){
			if (A[e]<=y) ++m;
		}
		answer(m);
		return;
	}


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