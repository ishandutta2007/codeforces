#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long w, k, n;

	cin >> k >> n >> w;

	cout << max(w*(w+1)/2*k - n, 0ll);
}