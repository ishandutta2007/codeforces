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

const int N=1e6+99,M=19;

int t;
ll n,k,a[N],b[N],sum[N],Pow[N];

bool check(ll x){
	ll res=0,mx=0,copy=x;
	f(i,0,M+1){
		ll mv=x%10;
		x/=10;
		sum[i]=mv*a[i];
	}
	x=copy;
	f_(i,M,0){
		sum[i]+=sum[i+1];
	}
	mx=sum[0];
	f(i,0,M){
		ll mv=x%10;
		x/=10;
		if(mv){
			maxm(mx,res+(mv-1)*a[i]+sum[i+1]);
		}
		res+=9ll*a[i];
	}
	//cout<<copy<<" "<<mx<<endl;
	if(mx>k) return 0;
	return 1;
}

int main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	Pow[0]=1;
	f(i,1,M+1) Pow[i]=10ll*Pow[i-1];
	cin>>t;
	while(t--){
		int s=0;
		ll ans=0;
		f(i,0,M+1) a[i]=-1,b[i]=-1;
		cin>>n>>k;
		f(i,0,n){
			int x;
			cin>>x;
			a[x]=1;
		}
		f(i,0,M+1){
			if(a[i]==-1){
				a[i]=a[i-1]*10ll;
			}
		}
			//if(b[a[i]]==-1){
			//	b[a[i]]=i;
			//}
		/*f(i,0,M+1){
			cout<<b[i]<<" ";
		}
		cout<<endl;
		f(i,0,10){
			ll x=k%10;
			k/=10;
			ans+=k*Pow[b[i]];
		}*/
		ll l=0,r=2e18;
		while(l+1<r){
			ll mid=(l+r)/2;
			if(check(mid)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		cout<<r<<endl;
	}
}