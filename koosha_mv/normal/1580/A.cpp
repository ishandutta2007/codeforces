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

const int N=409;

int n,m,t,ans,a[N][N],b[N][N],c[N],d[N];

void solve(int x,int y){
	f(i,1,m+1){
		c[i]=b[y-1][i]-b[x][i]+(1-a[x][i])+(1-a[y][i]);
		d[i]=y-x-1-(b[y-1][i]-b[x][i]);
	}
	int res=N*N;
	f(i,1,m+1){
		if(i>3){
			minm(res,c[i-1]+c[i-2]+d[i-3]);
			minm(ans,res+d[i]);
		}
		res+=c[i];
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
	
	ans=N*N;
	cin>>n>>m;
	f(i,1,n+1){
		string s;
		cin>>s;
		f(j,1,m+1){
			a[i][j]=(s[j-1]=='1');
		}
	}
	f(i,1,n+1)
		f(j,1,m+1)
			b[i][j]=a[i][j]+b[i-1][j];
	f(i,1,n+1){
		f(j,i+4,n+1){
			solve(i,j);
		}
	}
	cout<<ans<<endl;
	
	}
}