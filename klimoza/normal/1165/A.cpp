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
ll mod = 998244353;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, x, y;
	string st;
	cin >> n >> x >> y;
	cin >> st;
	reverse(st.begin(), st.end());
	int cnt = st[y] == '0';
	for (int i = 0; i < x; i++) {
		if (i == y) continue;
		cnt += (st[i] == '1');
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}