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

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	set<int> good;
	for (int i = 1; i < (1 << n); i++) {
		if (i == x) continue;
		good.insert(i);
	}
	vector<int> a;
	int cur = 0;
	while(true) {
		if (good.empty()) break;
		int f = *good.begin();
		a.push_back(f ^ cur);
		cur = f;
		good.erase(cur);
		good.erase(cur ^ x);
	}
	cout << a.size() << endl;
	for (int i : a) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}