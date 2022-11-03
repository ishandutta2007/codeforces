#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>

using namespace std;

const int magic = 300;
int dp[magic][100001];
const int INF = 1e9;


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < magic; i++)
		for (int j = 0; j < n; j++) {
			dp[i][j] = INF;
		}
	for (int i = 1; i < magic; i++) {
		for (int j = n - 1; j >= 0; j--) {
			int to = j + i + a[j];
			if (to >= n)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i][to] + 1;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int p, k;
		cin >> p >> k; p--;
		int cnt = 0;
		if (k >= magic) {
			while (p < n) {
				p = p + a[p] + k;
				cnt++;
			}
		}
		else
			cnt = dp[k][p];
		cout << cnt << '\n';
	}

	return 0;
}