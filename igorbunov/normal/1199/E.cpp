#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	int q;
	cin >> q;

	for (int _ = 0; _ < q; _++) {
		int n, m;
		cin >> n >> m;
		n *= 3;

		vector<bool> used(n);
		vector<int> ans;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			if (!used[a] && !used[b]) {
				ans.push_back(j + 1);
				used[a] = true;
				used[b] = true;
			}

		}

		if (ans.size() >= n / 3) {
			cout << "Matching\n";

			for (int j = 0; j < n / 3; j++) {
				cout << ans[j] << " ";
			}
		} else {
			cout << "IndSet\n";

			int count1 = 0;
			for (int j = 0; j < n; j++) {
				if (count1 == n / 3) {
					break;
				}

				if (!used[j]) {
					cout << j + 1 << " ";
					count1++;
				}
			}
		}

		cout << endl;
	}
}