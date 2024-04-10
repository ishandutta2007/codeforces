#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<pair<int, pair<int, int>>> v;
int par[200001], dep[200001];

int main() {
	int n;
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i].second.first >> v[i].second.second >> v[i].first;
		par[i] = -1;
		dep[i] = 0;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int x1 = v[i].second.first, y1 = v[i].second.second;
			int x2 = v[j].second.first, y2 = v[j].second.second;
			int r1 = v[i].first, r2 = v[j].first;
			if(x2 - r2 > x1 - r1) continue;
			if(x2 + r2 < x1 + r1) continue;
			if(y2 - r2 > y1 - r1) continue;
			if(y2 + r2 < y1 + r1) continue;
			par[i] = j;
			break;
		}
	}
	for(int i = n-1; i >= 0; i--) {
		if(par[i] == -1) continue;
		dep[i] = 1 + dep[par[i]];
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(dep[i] == 0 || dep[i]%2) ans += (ll)v[i].first * v[i].first;
		else ans -= (ll)v[i].first * v[i].first;
	}
	long double d = ans;
	d *= (long double)(3.14159265358979323846);
	cout << fixed << setprecision(10) << d << '\n';
}