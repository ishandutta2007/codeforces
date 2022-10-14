#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
using namespace std;

long long n, m, ksum = 0, ans = 0;
char c, pc = '\0';
vector<long long> v;
multiset<long long> b;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	v.resize(n);
	for (auto& i : v)
		cin >> i;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if(pc != c) {
			ans += ksum;
			ksum = 0;
			b.clear();
		}
		b.insert(v[i]);
		ksum += v[i];
		if(b.size() > m) {
			ksum -= *b.begin();
			b.erase(b.begin());
		}
		pc = c;
	}
	ans += ksum;
	cout << ans;
}