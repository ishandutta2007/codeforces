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


int adj[100][100];
const int N=82;
const int K=11;
int dp[N][N][K];	
long long dp2[N][N][K];
int ans;
void do2(int n){
	For(i,n){ dp[i][i][2]=INF;
	}
	For(i,n){
		For(j,n){
			if (i!=j){
				dp[i][i][2]=min(dp[i][i][2],adj[i][j]+adj[j][i]);
			}
		}
	}
}

void do4(int n){
	For(i,n) dp[i][i][4]=INF;

	For(i,n){
		For(j,n){
			For(k,n){
				For(l,n){
					if (i==j || j==k || k==l || i==l) continue;
					dp[i][i][4]=min(dp[i][i][4],adj[i][j]+adj[j][k]+adj[k][l]+adj[l][i]);
				}
			}
		}
	}
}

void do6(int n){
	dp[0][0][6]=INF;

	For(i,n){
		For(j,n){
			For(k,n){
				For(l,n){
					For(m,n){
						if (0!=i && i!=j && j!=k && k!=l && l!=m && m!=0 && 0!=k && i!=l && j!=m){
							dp[0][0][6]=min(dp[0][0][6],adj[0][i]+adj[i][j]+adj[j][k]+adj[k][l]+adj[l][m]+adj[m][0]);
						}
					}
				}
			}
		}
	}
}

int parity[N];


void randcol(int n){
	parity[0]=0;
	for(int i=1;i<n;++i){
		parity[i]=rand()%2;
	}
}


long long sol(int n,int k){
	
	For(j,n){
		For(z,k+1) dp2[0][j][z]=INF;
	}
	dp2[0][0][0]=0;

	vi od,ev;
	For(i,n){
		if (parity[i]) od.pb(i);
		else ev.pb(i);
	}

	for(int len=1;len<=k;++len){
		int tlen=len%2;
		int src=0;
		For(des,n){
			if (parity[des]!=tlen) continue;
			// if (len==0){
			// 	if (src!=des) continue;
			// 	dp2[src][des][len]=0;
			// 	continue;
			// }
			if (tlen){
				for(auto mid:ev){
					dp2[src][des][len]=min(dp2[src][mid][len-1]+adj[mid][des],dp2[src][des][len]);
				}
			}
			else{
				for(auto mid:od){
					dp2[src][des][len]=min(dp2[src][mid][len-1]+adj[mid][des],dp2[src][des][len]);
				}
			}
		}
	}
	return dp2[0][0][k];
}

void solve(){
	srand(time(NULL));
	int n,k;
	cin>>n>>k;
	int mn=INF;
	For(i,n){
		For(j,n) {
			cin>>adj[i][j];
			if (i!=j) mn=min(mn,adj[i][j]);
		}
	}
	do2(n);
	if (k==2){
		cout<<dp[0][0][2]<<endl;
		return;
	}
	do4(n);
	if (k==4){
		cout<<dp[0][0][4]<<endl;
		return;
	}
	// if (k==6){
	// 	do6(n);

	// 	cout<<dp[0][0][6]<<endl;
	// 	return;
	// }
	long long ans=dp[0][0][2]*1ll*(k/2);
	if ((k%4)==0){
		ans=min(ans,dp[0][0][4]*1ll*(k/4));
	}
	int iter=20240;


	For(i,iter){
		randcol(n);
		ans=min(ans,sol(n,k));
		if (ans==0 || ans<=mn*k) break;
	}
	assert(ans>=mn*k);
	cout<<ans<<endl;
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