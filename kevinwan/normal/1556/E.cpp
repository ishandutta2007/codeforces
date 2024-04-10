#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=1e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=31607;
 
struct sptbl {
	ll a[mn][17];
	sptbl(ll s[mn]){
		for(int i=0;i<mn;i++)a[i][0]=s[i];
		for(int i=1;i<17;i++){
			for(int j=0;j+(1<<i)<=mn;j++){
				a[j][i]=min(a[j][i-1],a[j+(1<<(i-1))][i-1]);
			}
		}
	}
	ll get(int l,int r) {
		int lv=31-__builtin_clz(r-l+1);
		return min(a[l][lv],a[r-(1<<lv)+1][lv]);
	}
};
ll psa[mn];
ll d[mn], a[mn],b[mn], np[mn];
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)d[i]=b[i]-a[i],psa[i]=psa[i-1]+d[i];//, cerr << d[i] << " ";
	//cerr << endl;
	sptbl pmin {psa};
	for(int i=1;i<=n;i++)np[i]=-psa[i];
	sptbl npmax {np};
	while(q--){
		int l,r;
		cin>>l>>r;
		//cerr << pmin.get(l-1,r)<< " " << psa[l-1] << " " << psa[r] << endl;
		if(psa[l-1]!=psa[r] || pmin.get(l-1,r)<psa[l-1]) printf("-1\n");
		else printf("%lld\n", -npmax.get(l-1,r)-psa[l-1]);
	}
}