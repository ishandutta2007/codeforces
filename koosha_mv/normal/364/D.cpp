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

int n,t,Test=12,cnt[N];
ll ans=1,a[N];

void solve(ll x){
	vector<ll> v;
	for(ll i=1;i*i<=x;i++){
		if(x%i==0){
			v.pb(i);
			if(i*i!=x){
				v.pb(x/i);
			}
		}
	}
	sort(v.begin(),v.end());
	f(i,1,n+1){
		ll u=__gcd(x,a[i]);
		cnt[lower_bound(v.begin(),v.end(),u)-v.begin()]++;
	}
	f(i,0,v.size()){
		int sum=0;
		f(j,i,v.size()){
			if(v[j]%v[i]==0){
				sum+=cnt[j];
			}
		}
		if(2*sum>=n) maxm(ans,v[i]);
	}
	f(i,0,v.size())
		cnt[i]=0;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	while(Test--){
		solve(a[(1ll*rand()*rand()+rand())%n+1]);
	}
	cout<<ans;
}