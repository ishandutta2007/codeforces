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

const int N=(1<<21);

ll n,a[N],b[N],c[N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,(1<<n)){
		char c;
		cin>>c;
		a[i]=c-'0';
		a[i]<<=(nb(i)<<1);
	}
	f(i,0,(1<<n)){
		char c;
		cin>>c;
		b[i]=c-'0';
		b[i]<<=(nb(i)<<1);
	}
	f(l,0,n){
		f(mask,0,(1<<n)){
			if(bit(mask,l)==0){
				a[mask^(1<<l)]+=a[mask];
				b[mask^(1<<l)]+=b[mask];
			}
		}
	}
	f(mask,0,(1<<n)) c[mask]=a[mask]*b[mask];
	f(l,0,n){
		f(mask,0,(1<<n)){
			if(bit(mask,l)==0){
				c[mask^(1<<l)]-=c[mask];
			}
		}
	}
	f(mask,0,(1<<n)){
		ll ans=(c[mask]>>(nb(mask)<<1))&3;
		cout<<ans;
	}
}