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

int mi,mic,ma,mac,sc;

void solve(){
	int n;
	cin>>n;
	mi=INT_MAX,ma=INT_MIN,sc=INT_MAX;
	for(int i=0;i<n;i++){
		int l,r,c;
		cin>>l>>r>>c;
		if(l<mi)mi=l,mic=c,sc=INT_MAX;
		else if(l==mi&&c<mic)mic=c;
		if(r>ma)ma=r,mac=c,sc=INT_MAX;
		else if(r==ma&&c<mac)mac=c;
		if(l==mi&&r==ma)sc=min(sc,c);
		printf("%d\n",min(mic+mac,sc));
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