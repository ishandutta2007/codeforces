#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> ostream& operator<<(ostream& os, vector<T> V){
	os<<"[ "; for(auto v : V) os << v << " "; return os<<"]";
}
template<class L, class R> ostream& operator<<(ostream& os, pair<L, R> P){
	return os<< "(" << P.first << " , " << P.second << ")";
}
#define TRACE
#ifdef TRACE
template< typename Arg1>
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
void __f(const char* name, Arg1&& arg1){
	cout << name << ": "<< arg1 << endl;
}
template < typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma=strchr(names+1 , ','); cout.write(names, comma-names) << " : " << arg1 << " | ";
	__f(comma+1 , args...);
}
#else 
#define trace(...) 1
#endif
#define ll long long
#define ld long double
#define pll pair<ll, ll> 
#define pii pari<ll, ll>
#define F first
#define S second
#define I insert
#define pb push_back
#define all(x) x.begin(), x.end()
#define vi vector<ll>
#define vll vector<ll>
#define For(i,n) for(ll i=0;i<n;++i)
#define Rep(i,n) for(ll i=1;i<=n;++i)
const ll mod=1e9+7;
// ll mod;



const ll maxn=1e6+100;
inline ll add(ll x,ll y){
	x+=y; return (x>=mod)?x-mod:x;
}
inline ll sub(ll x,ll y){
	x-=y;return (x<0)?x+mod:x;
}
inline ll mul(ll x,ll y){
	return (x*1ll*y)%mod;
}

ll fpow(ll x,ll y){
	if (!y) return 1;

	ll ret=1;

	while(y){
		if ((y%2)==1) ret=mul(ret,x);
		y/=2;
		x=mul(x,x);
	}
	return ret;
}

ll inv(ll x){
	return fpow(x,mod-2);
}


const ll N=101;
struct matrix{
	ll n;

	ll M[N][N];
	matrix(ll n): n(n){};
	inline ll add(ll x,ll y){
		x+=y; return (x>=mod)?x-mod:x;
	}
	inline ll sub(ll x,ll y){
		x-=y;return (x<0)?x+mod:x;
	}
	inline ll mul(ll x,ll y){
		return (x*1ll*y)%mod;
	}
	void eye(){
		For(i,n){
			For(j,n) M[i][j]=(i==j)?1:0;
		}
	}
	void eye(ll n){
		this->n=n;
		eye();
	}
	matrix mul(const matrix& p){
		matrix Z(n);

		For(i,n){
			For(j,n){
				Z.M[i][j]=0;

				For(k,n){
					Z.M[i][j]=add(Z.M[i][j],mul(M[i][k],p.M[k][j]));
				}
			}
		}
		return Z;
	}
	matrix add(matrix& p){
		matrix Z(n);
		For(i,n) For(j,n) Z.M[i][j]=add(M[i][j],p.M[i][j]);
		return Z;
	}

};
ll f[N],ib[N],ls[maxn];
ll Y[N];
ll nw[maxn];

ll Z[N];

matrix expo(ll n,matrix Z,ll tmp){
	matrix Ans(n);
	Ans.eye();

	while(tmp){
		if ((tmp%2)==1){
			Ans=Ans.mul(Z);
		}
		Z=Z.mul(Z);
		tmp/=2;
	}
	return Ans;
}
// void prll(matrix X,ll m){
// 	For(i,m){
// 		For(j,m){
// 			cout<<X.M[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	cout<<endl;
// }
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(25);
	ll n,l,m,u;
	cin>>n>>l>>m;
	// mod=m;
	// trace(n,l,m);
	Rep(i,n){
		cin>>u;
		u%=m;
		f[u]=add(f[u],1);
	}
	Rep(i,n){
		cin>>u;
		ls[i]=u;
		++ib[u%m];
	}
	Rep(i,n){
		cin>>u;
		nw[i]=u;
		// ++ls[u%m];
		++Z[(u+ls[i])%m];
	}


	matrix M(m);

	For(i,m){
		For(j,m){
			// trace(i,j);
			M.M[i][j]=ib[(i-j+m)%m];
			// trace(M.M[i][j],sub(i,j));
		}
	}
	// prll(M,m);
	matrix X=expo(m,M,l-2);
	// prll(X,m);
	For(i,m){
		Y[i]=0;

		For(j,m){
			Y[i]=add(Y[i],mul(X.M[i][j],f[j]));

		}
		// trace(i,Y[i]);
	}
	ll res=0;

	For(i,m){
		// trace(Z[i]);
		res=add(res,mul(Y[i],Z[(m-i)%m]));
	}
	cout<<res<<endl;
	// trace(res);




	return 0;
}