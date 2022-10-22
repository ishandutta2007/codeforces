#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
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

const int N=1e6+99;

int n,t,a[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

int main(){
	cin>>n;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0 && n!=4){
			return cout << "NO", 0;
		}
	}
	if(n==4){
		cout << "YES" << '\n';
		cout << 1 << " " << 3 << " " << 2 << " " << 4 << '\n';
		return 0;
	}
	cout << "YES" << '\n';
	cout << 1 << " ";
	f(i, 1, n-1){
		cout << 1ll * (i+1) * pow(i,n-2,n) % n << " ";
	}
	if(n>1) cout << n;
}