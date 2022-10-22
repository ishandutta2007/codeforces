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

int n,t,k,a[N];

void Main(){
	cin>>n>>k;
	if(k==1){
		cout<<"YES"<<endl;
		f(i,1,n+1) cout<<i<<endl;
		return ;
	}
	if(n&1){
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	f(i,1,n+1){
		int x;
		if(i%2==1){
			x=(i-1)*k+1;
		}
		else{
			x=(i-2)*k+2;
		}
		f(j,0,k){
			cout<<x<<" ";
			x+=2;
		}
		cout<<endl;
	}
}

main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		Main();
	}
}