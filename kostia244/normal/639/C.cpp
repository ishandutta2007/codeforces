#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;
ll n, k, a[200200], ta[200200];
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	memset(a, 0, sizeof a);
	memset(ta, 0, sizeof ta);
	cin >> n >> k;
	for(int i = 0; i <= n; i++)
		cin >> a[i], ta[i] = a[i];
	int ls = 0;
	for(int i = 0; i + 1 < 200200; i++) {
		a[i+1]+=a[i]/2, a[i]%=2;
		if(a[i])
			ls=a[i];
	}
	if(ls == -1){

		for(int i = 0; i < 200200; i++)
			a[i]*=-1;
		for(int i = 0; i <=n; i++)
			ta[i]*=-1;
	}
	for(int i = 200199; i>=0; i--) {
		if(a[i] == -1) {
			int j = i+1;
			a[i]=1;
			while(a[j]!=1)a[j++]=1;
			a[j]=0;
		}
	}
	int l = 0, r = 200199;
	while(!a[l]) l++;
	while(!a[r]) r--;
	if(r-l > 31) {
		cout << 0;
		return 0;
	}
	ll val = 0, ol = l;
	l = max(l-30, 0);
	for(int i = l; i <= r; i++) {
		val += a[i] * (1ll<<(i-l));
	}
	r = ol;
	ll ans = 0;
	for(int i = l; i <= min(n, (ll)r); i++) {
		ll tval = val - ta[i]*(1ll<<(i-l));
		ll sval = (tval>>(i-l))<<(i-l);
		if((i!=n||tval)&&tval==sval) {
			ans += (abs(tval)>>(i-l)) <= k;
		}
	}
	cout << ans;
}