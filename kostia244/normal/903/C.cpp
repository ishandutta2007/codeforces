#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 998244353ll;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	map<int, int> a;
	int t;
	cin >> n;
	while(n--) cin >> t, a[t]++;
	t = 0;
	for(auto i : a) t = max(t, i.second);
	cout << t;
}