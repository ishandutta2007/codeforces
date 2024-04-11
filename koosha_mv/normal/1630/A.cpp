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
	if(k==n-1){
		if(n==4){
			cout<<-1<<endl;
			return ;
		}
		f(i,0,n){
			if(nb(i)!=1 && nb(i)!=nb(n-1)-1 && (i&1)){
				cout<<i<<" "<<n-1-i<<endl;
			}
		}
		f(i,0,n){
			if(nb(i)==1){
				int x=(i*2)%n;
				if(x==0) x=1;
				cout<<i<<" "<<((n-1)^x)<<endl;
			}
		}
		return ;
	}
	if(k==0){
		f(i,0,n/2){
			cout<<i<<" "<<n-1-i<<endl;
		}
		return ;
	}
	f(i,1,n-1){
		if(i!=k && i!=n-1-k && (i&1)){
			cout<<i<<" "<<n-1-i<<endl;
		}
	}
	cout<<n-1<<" "<<k<<endl;
	cout<<0<<" "<<n-1-k<<endl;
}

main(){
	cin>>t;
	while(t--){
		Main();
	}
}