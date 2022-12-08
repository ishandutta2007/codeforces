#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>


#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9+ 7;

mt19937 mrand(random_device{} ());

bool smart(int n, int k) {
	if (k % 3) {
		return n % 3;
	}
	int f = n % (k + 1);
	if (f >= k - 2) return 1;
	if (f % 3 == 0) return 0;
	return 1;
}

bool stupid(int n, int k) {
	vector<bool> a(n + 1, false);
	//cout << "0 ";
	for (int i = 1; i <= n; i++) {
		a[i] = !a[i - 1];
		if (i >= 2) a[i] = a[i] | !a[i - 2];
		if (i >= k) a[i] = a[i] | !a[i - k];
		/*if (a[i]) cout << "1 ";
		else cout << "0 ";*/
	}
	//cout << endl;
	return a[n];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (smart(n, k)) cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;
}