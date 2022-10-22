#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) builtin_popcount(x)
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

const int N=1009;

int n,m,ans,a[N][N],r[N][N],c[N][N],mark[N][N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1){
		string s;
		cin>>s;
		s=' '+s;
		f(j,1,m+1){
			a[i][j]=(s[j]=='B');
		}
	}
	f_(i,n,1){
		f_(j,m,1){
			a[i][j]^=c[i][j];
			if(a[i][j]){
				mark[i][j]=1;
				c[i][j]^=1;
				ans++;
			}
			c[i][j-1]^=c[i][j];
			c[i-1][j]^=c[i][j];
			c[i-1][j-1]^=c[i][j];
		}
	}
	f(i,1,n){
		f(j,1,m){
			if(mark[i][j] && mark[i][m] && mark[n][j] && mark[n][m]){
				ans--;
				cout<<ans;
				return 0;
			}			
		}
	}
	cout<<ans;
}