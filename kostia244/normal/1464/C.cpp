#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1<<17;
using ll = long long;
string rev(string s) {
	for(auto &i : s) i ^= '0'^'1';
	return s;
}
/*
vector<string> a[11];
vector<string> f(int l) {
	if(!a[l].empty()) return a[l];
	for(int i = 1; i < l; i++) {
		for(auto x : f(i))
			for(auto y : f(l-i)) {
				a[l].push_back(rev(x) + y);
			}
	}
	sort(all(a[l]));
	a[l].erase(unique(all(a[l])), a[l].end());
	return a[l];
}*/
ll cost(char c) {
	return 1ll<<(c-'a');
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, t;
	string s;
	cin >> n >> t;
	cin >> s;
	t -= cost(s.back());
	s.pop_back();
	t += cost(s.back());	
	s.pop_back();
	array<ll, 100> cnt {};
	for(auto &i : s) {
		cnt[i-'a'+1]++;
		t += cost(i);
	}
	if(t < 0) return cout << "No\n", 0;
	for(ll b = 0; b < 62; b++) {
		if((t>>b)&1) cnt[b]--;
		if(cnt[b] < 0) return cout << "No\n", 0;
		cnt[b+1] += cnt[b]/2;
	}
	cout << "Yes\n";
}