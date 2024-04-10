#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

#define ft first
#define sc second

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int64_t n;
	cin >> n;
	for (int64_t i = 1; i * i <= n; i++){
		if ((n - 1) % i != 0)
			continue;
		int64_t gg = (n - 1) / i;
		if ((gg - i - 1) % 2)
			continue;
		int64_t y = (gg - i - 1) / 2;
		if (i * i + 2 * i * y + i + 1 != n)
			continue;
		if (y <= 0){
			continue;
		}
		cout << i << ' ' << y << '\n';
		return 0;
	}
	cout << "NO\n";

}