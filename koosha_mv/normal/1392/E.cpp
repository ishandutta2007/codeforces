#include <bits/stdc++.h>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=27;

int n,t,q;
ll m[N][N];

int main(){
	f(i,0,N)
		f(j,0,N){
			if(i==0) m[i][j]=0;
			else m[i][j]=(1-m[i-1][j+1]);
		}
	f(i,1,N)
		f(j,0,N)
			if(m[i][j]) m[i][j]=(1ll<<(1ll*(i+j)));
	cin>>n;
	f(i,0,n){
		f(j,0,n)
			cout<<m[i][j]<<" ";
		cout<<'\n';
	}
	cin>>q;
	while(q--){
		ll k;
		cin>>k;
		pair<int,int> now=mp(0,0);
		f(q,0,2*n-1){
			cout<<now.F+1<<" "<<now.S+1<<'\n';
			//cout<<(0<(k&(1ll<<(q+1ll))))<<" "<<(0<m[now.F][now.S+1])<<'\n';
			if(now.F==n-1 || (((0<(k&(1ll<<(q+1ll))))==(0<m[now.F][now.S+1])) && now.S+1<n))
				now.S++;
			else
				now.F++;
		}
	}
}