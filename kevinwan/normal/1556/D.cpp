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
const int mn=4e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=31607;
 
ll sum(int i,int j) {
	cout << "or " << i << " " << j << endl;
	ll a, b;
	cin >> a;
	cout << "and " << i << " " << j << endl;
	cin >> b;
	return a+b;
}
 
ll a[mn];
 
int main() {
	//cin.tie(0);
	//cin.sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	for(int i=2;i<=n;i++)a[i]=sum(1,i);
	ll s = sum(2,3);
	a[1]=(a[2]+a[3]-s)/2;
	for(int i = 2;i<=n;i++)a[i]-=a[1];
	sort(a+1,a+n+1);
	cout << "finish " << a[k] << endl;
}