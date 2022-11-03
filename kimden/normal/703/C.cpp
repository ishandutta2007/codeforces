#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 100002;
const int mod = 1000000007;
const double eps = 1e-6;

int c[maxn];
vector<int> cap;

int main()
{
	ll n,w,v,u;
	cin >> n >> w >> v >> u;
	double mn,mx,val;
	ll x,y;
	cin >> x >> y;
	val = (v*1.*(w-y))/(1.*u)+x;
	mn = mx = val;
	for(int i=1;i<n;i++){
		cin >> x >> y;
		val = (v*1.*(w-y))/(1.*u)+x;
		mn = min(mn,val);
		mx = max(mx,val);
	}
	val = v*1.*w/(1.*u);
	if(mn>=val-eps || mx<=val+eps){
		cout << setprecision(9) << val/(1.*v);
	}else{
		cout << setprecision(9) << mx/(1.*v);
	}
}