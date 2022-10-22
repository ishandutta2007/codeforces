#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

const int N=1e6+99,lg=20;

int n,t,a[N],dist[N],A[N][lg],B[N][lg];

void Main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		A[i][0]=i-1;
		B[i][0]=i-1;
		while(A[i][0]!=0 && a[A[i][0]]>a[i]) A[i][0]=A[A[i][0]][0];
		while(B[i][0]!=0 && a[B[i][0]]<a[i]) B[i][0]=B[B[i][0]][0];
		f(l,1,lg) A[i][l]=A[A[i][l-1]][l-1],B[i][l]=B[B[i][l-1]][l-1];
	}
	dist[1]=0;
	f(i,2,n+1){
		if(a[i-1]<a[i]){
			int now=i;
			f_(l,lg-1,0){
				if(B[i][0]<A[now][l]){
					now=A[now][l];
				}
			}
			dist[i]=dist[now]+1;
		}
		else{
			int now=i;
			f_(l,lg-1,0){
				if(A[i][0]<B[now][l]){
					now=B[now][l];
				}
			}
			dist[i]=dist[now]+1;
		}
	}
	cout<<dist[n]<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}