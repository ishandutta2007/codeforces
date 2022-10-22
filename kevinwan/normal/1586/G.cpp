#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 4e5+10;
const int SIZE = 600;
const int BLOCKS = mn/SIZE+10;
const ll mod = 1e9+7;
int a[mn],b[mn];
ll bit[mn];
void upd(int a,ll b){for(;a<mn;a+=a&-a)bit[a]+=b,bit[a]%=mod;}
ll qu(int a){ll b=0;for(;a;a-=a&-a)b+=bit[a],b%=mod;return b;}
ll rt[mn],ft[mn];
bool ins[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	vi o(n);
	iota(o.begin(),o.end(),1);
	sort(o.begin(),o.end(),[](int i,int j){return b[i]<b[j];});
	for(int k=0;k<n;k++){
		int i=o[k];
		rt[i]=(1+qu(b[i])-qu(a[i]))%mod;
		upd(a[i],rt[i]);
		//cerr<<rt[i]<<endl;
	}
	vi s;
	int m;
	cin>>m;
	s.resize(m);
	for(int i=0;i<m;i++){
		cin>>s[i];
		ins[s[i]]=1;
	}
	int la=0;
	ll ans=0;
	for(int k=n-1;k>=0;k--){
		int i=o[k];
		upd(a[i],-rt[i]);
		if(ins[i]&&a[i]>la){
			ans+=qu(b[i])-qu(la)+1;
			ans%=mod;
			la=a[i];
		}
	}
	if(ans<0)ans+=mod;
	printf("%lld\n",ans);
}