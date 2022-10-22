#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<ll> a, x;
set<ll> s;
int pref[200001];
vector<pair<ll, ll>> p;
ll BIG = 3000000000000000001;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll t, k;
	cin >> n >> t;
	a.resize(n);
	x.resize(n);
	p.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		p[i] = {a[i] + t, BIG};
	}
	bool sad = false;
	for(int i = 0; i < n; i++) {
		cin >> k;
		k--;
		if(k < i) sad = true;
		p[k].first = max(p[k].first, a[i] + t);
		if(k < n-1) p[k].second = min(p[k].second, a[k+1] + t);
		pref[i]++;
		pref[k]--;
	}
	if(sad) {
		cout << "No\n";
		return 0;
	}
	for(int i = 0; i < n; i++) {
		if(i > 0) pref[i] += pref[i-1];
		if(pref[i]) p[i].first = max(p[i].first, a[i+1] + t);
	}
	for(int i = 1; i < n; i++) {
		p[i].first = max(p[i].first, p[i-1].first);
	}
	for(int i = 0; i < n; i++) {
		for(ll j = p[i].first; j < p[i].second; j++) {
			if(s.find(j) == s.end()) {
				s.insert(j);
				break;
			}
			if(j == p[i].second-1) sad = true;
		}
	}
	if(sad || (s.size() != n)) {
		cout << "No\n";
		return 0;
	}
	else {
		cout << "Yes\n";
		for(ll i : s) cout << i << ' ';
	}
}