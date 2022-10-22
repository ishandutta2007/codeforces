#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
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

int a,b,n,t;

main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		int ans=0;
		while(a>0 && b>0){
			if(a>b) swap(a,b);
			if(b==n || (b>=n && (b-n)%a==0)) ans=1;
			b=b%a;
			
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
}