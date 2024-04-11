#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll bad = 0;

void search(vector<pair<int, int>> p, pair<int, int> o) {
	map<pair<int, int>, ll> q;
	for(auto i : p) {
		if(i == o) continue;
		i.first -=o.first;
		i.second -= o.second;
		int g = __gcd(i.first, i.second);
		i.first/=g;
		i.second/=g;
		if(i.first<0) i.first*=-1, i.second*=-1;
		q[i]++;
	}
	for(auto a : q)
		bad += a.second*1ll*(a.second-1)/2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<int, int>> a;
	a.resize(n);
	for(auto& i : a) cin >> i.first >> i.second;
	for(auto i : a) search(a, i);
	bad/=3;
	bad = n*(n-1)*(n-2)/6 - bad;
	cout << bad;
}