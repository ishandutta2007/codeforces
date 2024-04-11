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

const int N=1e6+99;

int n,t,res[N];
pair<int,int> a[N];

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		ll ans=0;
		cin>>n;
		f(i,0,n) cin>>a[i].F;
		f(i,0,n) a[i].S=i;
		sort(a,a+n);
		reverse(a,a+n);
		f(i,0,n){
			ans+=1ll*a[i].F*(i/2+1);
		}
		cout<<ans*2<<endl;
		cout<<0<<" ";
		f(i,0,n){
			if(i%2==0){
				res[a[i].S]=1+i/2;
			}
			else{
				res[a[i].S]=-1-i/2;
			}
		}
		f(i,0,n) cout<<res[i]<<" ";
		cout<<endl;
	}
}