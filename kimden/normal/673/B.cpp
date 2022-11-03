#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N=100099;
typedef long long ll;
ll binpow(ll a,int b){
	if(b==0) return 1;
	if(b==1) return a;
	ll a1 = binpow(a,(int)(b/2));
	ll ans = 1LL;
	if(b%2==1){
		ans *= a;
	}
	return a1 *ans * a1;
}

int main()
{
	int n,m;
	int o;
	cin >> n >> m;
	int u[N],v[N];
	int left=0,right=n-1;
	int lc,rc;
	ll ans;
	map<int,bool> mp;
	for(int i=0;i<m;i++){
		cin >> u[i] >> v[i];
		u[i]--;
		v[i]--;
		mp[u[i]]=true;
		mp[v[i]]=true;
		if(u[i]>v[i]){
			o = v[i];
			v[i] = u[i];
			u[i] = o;
		}
		left = max(left,u[i]);
		right = min(right,v[i]);
	}
	if(left>=right){
		cout << 0;
	}else{
		ans = (right-left);
		cout << ans;
	}
	return 0;
}