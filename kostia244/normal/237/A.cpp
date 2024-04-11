#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e6 + 55;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<pair<int,int>, int> x;
	int n, ans = 0;
	cin >> n;
	int h, m;
	while(n--) {
		cin >> h >> m;
		x[{h, m}]++;
	}
	for(auto i :x) ans =max(ans,i.second);
	cout << ans;
}