#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1111,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int n,t,ans,a[N][N],mark[N][N];

void calc0(int u,int v){
	if((u%4-v%4+4)%4==1){
		while(u<n && v<n){
			ans^=a[u][v];
			u+=2,v+=2;
		}
	}
}
void calc1(int u,int v){
	if((u%4+v%4)%4==0){
		while(u<n && 0<=v){
			ans^=a[u][v];
			u+=2,v-=2;
		}
	}
}

main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		f(i,0,n){
			f(j,0,n){
				cin>>a[i][j];
			}
		}
		f(i,0,n) calc0(0,i);
		f(i,1,n) calc0(i,0);
		f(i,0,n) calc1(0,i);
		f(i,1,n) calc1(i,n-1);
		cout<<ans<<'\n';
	}
}
/*
1
2
1 5
5 1
*/