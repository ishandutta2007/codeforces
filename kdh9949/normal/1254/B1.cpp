#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1000005;
const ll INF = ll(2e18);

int n;
ll a[N], b[N], c[N], ps[N], ss[N], cc, s, r = INF;
vector<ll> p;

ll g(){
	for(int i = 1; i <= cc; i++) ps[i] = ps[i-1] + c[i];
	ss[cc + 1] = 0;
	for(int i = cc; i >= 1; i--) ss[i] = ss[i+1] + c[i];
	ll pss = 0, sss = 0;
	for(int i = 2; i <= cc; i++) sss += ss[i];
	ll t = INF;
	for(int i = 1; i <= cc; i++){
		t = min(t, pss + sss);
		pss += ps[i];
		sss -= ss[i+1];
	}
	return t;
}

void f(ll x){
	for(int i = 0; i < n; i++) b[i] = a[i];
	ll t = 0;
	for(int i = 0, j; i < n; i = j){
		if(b[i] >= x) b[i] %= x;
		if(b[i] == 0){ j = i + 1; continue; }
		ll cs = b[i];
		c[1] = b[i]; cc = 1;
		j = i + 1;
		while(j < n){
			if(cs + b[j] >= x) break;
			cs += b[j];
			c[++cc] = b[j];
			j++;
		}
		c[++cc] = x - cs;
		b[j] -= (x - cs);
		t += g();
	}
	r = min(r, t);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s += a[i];
	}
	if(s == 1){ cout << "-1\n"; return 0; }
	ll ss = s;
	for(ll i = 2; i * i <= ss; i++){
		if(ss % i) continue;
		p.push_back(i);
		while(ss % i == 0) ss /= i;
	}
	if(ss > 1) p.push_back(ss);
	for(ll i : p) f(i);
	cout << r << '\n';
}