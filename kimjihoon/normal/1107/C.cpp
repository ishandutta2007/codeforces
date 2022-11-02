#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, k;
ll a[200009];
vector<ll> v;

ll pr(int s, int e)
{
	long long p = 0;
	v.clear();
	for (int i = s; i <= e; i++)
		v.push_back(a[i]);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size() && i < k; i++)
		p += v[i];
	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	string s; cin >> s;
	int r = 0;
	ll ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i == s.length() - 1 || s[i] != s[i + 1]) {
			ans += pr(r, i);
			r = i + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}