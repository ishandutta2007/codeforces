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

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		ll n, s, t;
		cin >> n >> s >> t;
		int m = s + t - n;
		s -= m; t -= m;
		cout << max(s, t) + 1 << endl;
	}
	//system("pause");
	return 0;
}