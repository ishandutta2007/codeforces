#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define ll long long


const int maxn = 1 << 17;
const int inf = 1000000000;

int s, S, k;
int f[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> s >> k; S = s;
	/*for (int i = 0; i < k; i++)
		f[i] = 0;
	f[k] = 1;
	int n = k+1;*/
	f[0] = 1;
	int n = 1;
	
	while (1) {
		bool flag = true;
		for (int i = max(n - k, 0); i < n; i++) {
			if (f[n] + f[i] > inf) {
				flag = false;
				break;
			} else f[n] += f[i];
		}
		if (!flag) {
			n--;
			break;
		} else n++;
	}

	vector<int> ans;
	for (int i = n; i >= 0; i--) {
		if (s >= f[i]) {
			s -= f[i];
			ans.push_back(f[i]);
		}
	}

	if (ans.size() == 1)
		ans.push_back(0);

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	/*for (int i = k; i <= n; i++)
		cout << f[i] << " ";
	cout << endl << n-k;*/

	return 0;
}