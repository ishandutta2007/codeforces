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

const int N=1e6+99;

int n,m,t,a[N];

void Main(){
	string s;
	cin>>n>>m>>s;	
	s=' '+s;
	f(i,1,n+1){
		a[i]=a[i-1]+(s[i]=='1');
	}
	if(m*a[n]%n){
		cout<<-1<<'\n';
		return ;
	}
	int cnt=m*a[n]/n;
	f(i,m,n+1){
		if(a[i]-a[i-m]==cnt){
			cout<<1<<'\n';
			cout<<i-m+1<<" "<<i<<'\n';
			return ;
		}
	}
	cout<<2<<'\n';
	f(i,1,m){
		int t=m-i;
		if(a[i]+a[n]-a[n-t]==cnt){
			cout<<1<<" "<<i<<'\n'<<n-t+1<<" "<<n<<'\n';
			return ;
		}
	}
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}