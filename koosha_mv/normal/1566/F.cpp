#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+99,Mx=2e9;
 
int n,m,t;
ll dp[N][2],a[N];
vector<pair<ll,ll> > e;
set<ll> s;
 
main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		s.clear();
		e.clear();
		cin>>n>>m;
		f(i,1,n+1){
			cin>>a[i];
			s.insert(a[i]);
		}
		a[++n]=1e10;
		s.insert(1e10);
		a[0]=-1e10;
		s.insert(-1e10);
		sort(a,a+1+n);
		f(i,0,m){
			ll l,r;
			cin>>l>>r;
			if(*s.lower_bound(l)>r){
				e.pb(mp(r,l));
			}
		}
		sort(e.begin(),e.end());
		reverse(e.begin(),e.end());
		f(i,1,n+1){
			vector<pair<ll,ll> > v;
			while(e.size() && e.back().F<a[i]){
				v.pb(mp(e.back().S,e.back().F));
				e.pop_back();
			}
			if(v.size()==0){
				dp[i][0]=dp[i-1][0];
				dp[i][1]=dp[i-1][0];
			}
			else{
				ll mx=-Mx;
				dp[i][0]=dp[i-1][0]+a[i]-v[0].S;
				dp[i][1]=dp[i-1][0]+(a[i]-v[0].S)*2ll;
				f(j,0,v.size()){
					ll cost=0;
					maxm(mx,v[j].F);
					if(j!=v.size()-1) cost=a[i]-v[j+1].S;
					minm(dp[i][0],dp[i-1][1]+mx-a[i-1]+cost);
					minm(dp[i][1],dp[i-1][1]+mx-a[i-1]+cost*2ll);
					minm(dp[i][0],dp[i-1][0]+(mx-a[i-1])*2+cost);
					minm(dp[i][1],dp[i-1][0]+(mx-a[i-1])*2+cost*2);
				}
			}
		}
		cout<<dp[n][0]<<endl;
	}
}