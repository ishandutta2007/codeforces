#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
inline void getv(vector<T>& v) {
	for (auto& i : v)
		cin >> i;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	long long n, c = 0;
	cin >> n;
	vi a(n);
	getv(a);
	sort(a.begin(), a.end());
	for(int i = 1; i <= n/2; i++) {
		c += pow(a[i - 1] + a[n - i], 2);
	}
	cout << c;
}