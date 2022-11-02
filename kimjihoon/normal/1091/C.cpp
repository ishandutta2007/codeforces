#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i != 0) continue;
		long long k = i;
		v.push_back(n / k + (n / k) * (n / k - 1) * k / 2);
		if (i != n / i) {
			int k = n / i;
			v.push_back(n / k + (n / k) * (n / k - 1) * k / 2);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << '\n';
	return 0;
}