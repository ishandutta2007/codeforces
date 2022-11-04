#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define maxn 100000
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
#define L 310
int am[(L + 1) * 2 * maxn + 2];
const int adding = (L + 1) * maxn;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 1;
	vi here;
	here.reserve(n);
	for(int i = -L; i <= L; i++) {
		here.clear();
		for(int j = 0; j < n; j++) {
			here.push_back(a[j] + j * i + adding);
			++am[a[j] + j * i + adding];
		}
		for(const auto& el : here) {
			ans = max(ans, am[el]);
			am[el] = 0;
		}
		here.clear();
	}
	for(int i = 0; i < n; i++) {
		for(int j = max(0, i - maxn / L); j < i; j++) {
			if((a[j] - a[i]) % (j - i) == 0) {
				++am[(a[j] - a[i]) / (j - i) + adding];
				here.push_back((a[j] - a[i]) / (j - i) + adding);
			}
		}
		for(const auto& el : here) {
			ans = max(ans, am[el] + 1);
			am[el] = 0;
		}
		here.clear();
	}
	cout << n - ans;

}