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
const ll mod=1e9+7;

int seg[mn*4],laz[mn*4];
void prop(int x){
	if(!laz[x])return;
	seg[x]+=laz[x];
	if(x*2+1<mn*4){
		laz[x*2]+=laz[x];
		laz[x*2+1]+=laz[x];
	}
	laz[x]=0;
}

void eval(int x){
	prop(x*2),prop(x*2+1);
	seg[x]=min(seg[x*2],seg[x*2+1]);
}

#define mid ((l+r)/2)
void upd(int x,int l,int r,int a,int b,int c){
	//cerr<<x<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
	prop(x);
	if(l==a&&r==b)laz[x]+=c;
	else{
		if(b<=mid)upd(x*2,l,mid,a,b,c);
		else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
		else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
		eval(x);
	}
}
vi v[mn];
ll sum[mn];
int a[mn];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		upd(1,1,mn-1,1,a[i],1);
	}
	for(int i=0;i<m;i++){
		v[i].clear();
		sum[i]=0;
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			sum[i]+=x;
			v[i].push_back(x);
		}
		upd(1,1,mn-1,1,(sum[i]+k-1)/k,-1);
	}
	for(int i=0;i<m;i++){
		int k=v[i].size();
		upd(1,1,mn-1,1,(sum[i]+k-1)/k,1);
		for(int x:v[i]){
			ll val=(sum[i]-x+k-2)/(k-1);
			upd(1,1,mn-1,1,val,-1);
			prop(1);
			printf("%d",seg[1]>=0);
			upd(1,1,mn-1,1,val,1);
		}
		upd(1,1,mn-1,1,(sum[i]+k-1)/k,-1);
	}
	printf("\n");
	for(int i=0;i<n;i++)upd(1,1,mn-1,1,a[i],-1);
	for(int i=0;i<m;i++){
		int k=v[i].size();
		upd(1,1,mn-1,1,(sum[i]+k-1)/k,1);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}