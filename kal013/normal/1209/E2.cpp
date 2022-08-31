/*/ Author: kal013 /*/
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <cstdio>
using namespace std;
// #define int long long
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
#define ll long long

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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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


int a[20][2005];
vi pos[2005];
int idx[2005];
int dp[13][1<<13+2];
bool cmp(int i,int j){
	For(k,pos[i].size()){
		if (k>=pos[j].size()) return false;
		if (pos[i][k]==pos[j][k]) continue;
		return pos[i][k]<pos[j][k];
	}
	return false;
}
int tot[2005][(1<<12)+2];
int tmp[(1<<12)+2];

void sol2(int col,int n){
	int msk=(1<<n);
	For(j,msk) {tot[col][j]=0;}
	// trace(col,n);
	// For(i,n) trace(a[i][col],col);
	For(rot,n){
		For(j,msk) tmp[j]=0;
		For(i,n){
			int j=(i+rot)%n;
			int v=(msk-1)^(1<<j);
			int por=(1<<j);
			int xx=v;
			// trace(v,xx);
			while(v>0){
				tmp[v^por]+=a[i][col];
				v=(v-1)&xx;
			}
			tmp[por]+=a[i][col];
		}
		For(j,msk){
			tot[col][j]=max(tot[col][j],tmp[j]);
		}	
	}

	
}

int mx(int msk,int col,int n){
	if (tot[col][msk]!=-1) return tot[col][msk];
	int res=0;
	For(rot,n){
		int tmp=0;
		For(i,n){
			int j=(i+rot)%n;
			if (msk&(1<<j)){
				tmp+=a[i][col];
			}
		}
		// trace(rot,msk,col,n);
		res=max(res,tmp);
	}
	tot[col][msk]=res;

	return res;
}

int sol(vi ids,int n){
	int m=ids.size();
	int msk=(1<<n);
	For(i,m+1) For(j,msk){
		dp[i][j]=0;
	}
	int ans=0;
	for(int i=1;i<=m;++i){
		// trace(i);
		int col=ids[i-1];
		
		sol2(col,n);
		For(j,msk){
			int x=j;
			while (x>0){
				dp[i][j]=max(dp[i-1][x]+mx(j-x,col,n),dp[i][j]);
				// trace(x,j);
				x=(x-1)&j;
			}
			dp[i][j]=max(dp[i][j],mx(j,col,n));
			ans=max(ans,dp[i][j]);
		}
	}
	return (ans);
}
void solve(){
	int n,m;
	cin>>n>>m;
	For(i,n){
		For(j,m) {cin>>a[i][j];}
	}
	For(j,m){
		pos[j].clear();
		For(i,n) pos[j].pb(a[i][j]);
		idx[j]=j;
		sort(all(pos[j]));
		reverse(all(pos[j]));
	}
	sort(idx,idx+m,cmp);
	
	vi ids;
	for(int i=m-1;i>=0 && ids.size()<n;--i){
		ids.pb(idx[i]);
	}
	// trace(ids);
	d1(sol(ids,n));




}
signed main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Uncomment codechef for large input files. Doesn't work on codeforces.
    #ifndef ONLINE_JUDGE
        freopen("error.txt","w",stderr);
    #endif
    fio;
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}