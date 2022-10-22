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

int n,t,a[N];

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	if(a[n]!=0){
		cout<<"YES"<<endl;
		cout<<1<<endl<<1<<" "<<n<<endl;
		exit(0);
	}
	f(i,1,n){
		if(a[i]!=0 && a[i]!=a[n]){
			cout<<"YES"<<endl;
			cout<<2<<endl<<1<<" "<<i<<endl<<i+1<<" "<<n<<endl;
			exit(0);
		}
	}
	f(i,1,n){
		f(j,i+1,n){
			if(a[i]!=0 && a[i]!=a[j] && a[j]!=a[n]){
				cout<<"YES"<<endl;
				cout<<3<<endl<<1<<" "<<i<<endl<<i+1<<" "<<j<<endl<<j+1<<" "<<n<<endl;
				exit(0);
			}
		}
	}
	cout<<"NO"<<endl;
}