#include <algorithm>
#include <iostream>
#include <cstdlib>
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
 
using namespace std;

#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	int a = 0;//1
	int b = 0;//0
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i]) {
			a++;
		} else {
			b++;
		}
	}

	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			x--;
			if (arr[x]) {
				a--;
				b++;
			} else {
				a++;
				b--;
			}
			arr[x] = 1 - arr[x];
		} else {
			int k;
			cin >> k;
			if (a >= k) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}

}