#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e6+99,lg=60,M=20;

int n,m,mod,a[N],b[N],d[N],mat[lg+9][lg+9],C[lg+9][lg+9];
int dp[(1<<M)][M+1];
ll t;

int Mn(int x,int y){
	return abs(x-y);
}
int Mx(int x,int y){
	return m-abs(m-(x+y));
}
void read(){
	cin>>m>>t>>mod;
	n=(1<<m);
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,m+1) cin>>b[i];
	f(i,0,m+1){
		C[0][i]=1;
		f(j,1,i+1)
			C[j][i]=(C[j][i-1]+C[j-1][i-1])%mod;
	}
}
void merge(int u,int v,int x){
	fill(d,d+m+2,0);
	f(i,0,m+1){
		f(j,0,m+1){
			f(k,0,m+1){
				int cnt1=(i+j-k)/2,cnt2=j-cnt1;
				if(Mn(i,j)<=k && Mx(i,j)>=k && (i+j+k)%2==0){
					Add(d[k],1ll*mat[u][i]*mat[v][j]%mod*C[cnt1][m-k]%mod*C[cnt2][k]%mod);
				}
			}
		}
	}
	f(i,0,m+1){
		mat[x][i]=d[i];
	}
}
void make(){
	f(i,0,m+1) mat[0][i]=b[i];
	f(i,0,lg-1) merge(i,i,i+1);
	mat[lg][0]=1;
	f(i,0,lg){
		if(t&(1ll<<i)){
			merge(i,lg,lg);
		}
	}
	f(i,0,m+1) b[i]=mat[lg][i];
}
void solve(){
	f(mask,0,n){ dp[mask][0]=a[mask]; }
	f(i,0,m){
		f_(k,i,0){
			f(mask,0,n){
				Add(dp[mask^(1<<i)][k+1],dp[mask][k]);
			}
		}
	}
	f(mask,0,n){
		int ans=0;
		f(k,0,m+1){
			Add(ans,1ll*dp[mask][k]*b[k]%mod);
		}
		cout<<ans<<'\n';
	}
}

main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	read(); 
	make();
	solve();
}