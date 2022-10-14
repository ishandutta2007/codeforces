#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second

#define N 200100
ll a[N], pre[N], ice[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(n) G(m)
	F(i, 0, n) cin >> a[i];
	pre[0] = 0;
	F(i, 1, n+1) pre[i] = pre[i-1] + a[i-1];
	F(i, 0, m) cin >> ice[i];
	sort(ice, ice+m);
	ll j = 0;
	ll ma = 0;
	F(i, 0, n){
		while(j < m && ice[j] <= 100*i) j++;
		ll prev = !j ? -2e9 : ice[j-1];
		ll nex = j == m ? 2e9 : ice[j];
		if(prev == 100*i) continue;
		ld nexH = min(100*i+(100*i-prev)-1e-4l, nex-1e-4l);
		ld avg = ((ld)(nexH+nex))/2.l;
		avg -= 1e-4l;
		ll fa = floor(avg/100.l);
		ll nexA = min(n-1, fa); //((nexH+nex)/100+1)/2-1);
		ma = max(ma, pre[nexA+1]-pre[i]);
	}
	cout << ma << endl;
}