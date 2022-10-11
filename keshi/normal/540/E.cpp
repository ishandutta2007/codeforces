#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, p[maxn], b[maxn];

ll merge(ll l, ll s){
	ll i = 0, j = 0, k = 0, r = l + s / 2, t = 0;
	while(i < s / 2 && j < s - s / 2){
		if(p[l + i] > p[r + j]){
			b[k++] = p[r + j];
			t += s / 2 - i;
			j++;
		}
		else{
			b[k++] = p[l + i];
			i++;
		}
	}
	while(i < s / 2){
		b[k++] = p[l + i];
		i++;
	}
	while(j < s - s / 2){
		b[k++] = p[r + j];
		j++;
	}
	for(i = 0; i < s; i++){
		p[l + i] = b[i];
	}
	return t;
}
 
ll m_sort(ll l, ll s){
	if(s < 2){
		return 0;
	}
	return m_sort(l, s / 2) + m_sort(l + s / 2, s - s / 2) + merge(l, s);
}

ll m, x, ans, a[maxn];

pll sp[maxn];

map<ll, bool> vis;
map<ll, ll> v;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> sp[i].F >> sp[i].S;
		if(!vis[sp[i].F]){
			a[m++] = sp[i].F;
			vis[sp[i].F] = 1;
		}
		if(!vis[sp[i].S]){
			a[m++] = sp[i].S;
			vis[sp[i].S] = 1;
		}
	}
	
	sort(a, a + m);
	
	for(ll i = 0; i < m; i++){
		p[i] = a[i];
		v[a[i]] = i;
	}
	
	for(ll i = 0; i < n; i++){
		swap(v[sp[i].F], v[sp[i].S]);
		swap(p[v[sp[i].F]], p[v[sp[i].S]]);
	}
	
	for(ll i = 0; i < m; i++){
		x = v[a[i]];
		ans += abs(a[x] - a[i]) - abs(x - i);
	}
	
	cout << ans + m_sort(0, m);
	return 0;
}