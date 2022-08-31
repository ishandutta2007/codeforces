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
#else
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


const ll INF=5e16;

inline ll dist(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}


ll gettim(int x1,int y1,int x2,int y2,int px,int py){
	return min(dist(x1,y1,px,py),dist(x2,y2,px,py))+dist(x1,y1,x2,y2);
}
void solve(){
	int x,y,ax,ay,bx,by;
	cin>>x>>y>>ax>>ay>>bx>>by;


	int xs,ys,t;
	cin>>xs>>ys>>t;


	vector<pii> V;

	V.pb({x,y});

	while(1){
		x=(ax*x+bx);
		y=(ay*y+by);
		V.pb({x,y});
		if (x>=INF || y>=INF) break;
	}

	int n=V.size();
	ll cnt=0;
	for(int i=0;i<n;++i){
		int mnx=V[i].F;
		int mny=V[i].S;
		int mxx=V[i].F;
		int mxy=V[i].S;
		for(int j=i;j<n;++j){
			mnx=min(mnx,V[j].F);
			mny=min(mny,V[j].S);
			mxx=max(mxx,V[j].F);
			mxy=max(mxy,V[j].S);
			ll res=gettim(mnx,mny,mxx,mxy,xs,ys);
			// if (mnx>=xs){
			// 	res=mxx-xs;
			// }
			// else if (mxx<=xs){
			// 	res=xs-mnx;
			// }
			// else{
			// 	res=min(xs-mnx+mxx-mnx,mxx-xs+mxx-mnx);
			// }

			// if (mny>=ys){
			// 	res+=mxy-ys;
			// }
			// else if (mxy<=ys){
			// 	res+=ys-mny;
			// }
			// else{
			// 	res+=min(ys-mny+mxy-mny,mxy-ys+mxy-mny);
			// }
			if (res<=t){
				cnt=max(cnt,j-i+1);
			}
		}
	}
	cout<<cnt<<endl;
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