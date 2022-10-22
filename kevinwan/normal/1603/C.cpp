#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 3e5+10;
const ll mod = 998244353;
ll num[mn];
ll nnum[mn];
ll a[mn];
bool see[mn];
void filtadd(vi &v, int x){
	if(!see[x]){
		see[x]=1;
		v.push_back(x);
	}
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=0,cans=0;
	vi rel;
	vi nrel;
	for(int i=n;i;i--){
		//cerr<<rel.size()<<endl;
		//for(int x:rel)cerr<<x<<" ";
		//cerr<<endl;
		nrel.clear();
		for(int x:rel){
			if(x>=a[i]){
				filtadd(nrel, a[i]);
				nnum[a[i]]+=num[x];
				num[x]=0;
				//cerr<<x<<" "<<a[i];
			}
			else{
				ll d=(a[i]-1)/x;
				cans+=num[x]*d;
				int nv=a[i]/(d+1);
				filtadd(nrel, nv);
				nnum[nv]+=num[x];
				num[x]=0;
				//cerr<<x<<" "<<d;
			}	
			//cerr<<endl;
		}
		//cerr<<endl;
		filtadd(nrel,a[i]);
		nnum[a[i]]++;
		swap(rel,nrel);
		for(int x:rel){
			num[x]=nnum[x];
			nnum[x]=0;
			see[x]=0;
		}
		cans%=mod;
		ans+=cans;
		ans%=mod;
	}
	for(int x:rel)num[x]=0;
	printf("%lld\n",ans);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}