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

 
//#pragma GCC_OPTIMIZE("ofast")
using namespace std;


#define int long long
#define endl "\n"


int MOD = 1000000007LL;

int pow(int a, int b) {
	if (b == 0) {
		return 1LL;
	}
	if (b % 2 == 0) {
		int c = pow(a, b / 2);
		return (c * c) % MOD;
	} else {
		return (a * pow(a, b - 1)) % MOD;
	}
}

void solve() {
	int n, p;
	cin >> n >> p;
	//cout << n << " " << p << endl;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.rbegin(), arr.rend());
	if (p == 1) {
		cout << n % 2 << endl;
		return;
	}
	int ind = 0;
	while (ind != n) {
		//cout << "I " <<  ind << endl;
		if (ind == n - 1) {
			cout << pow(p, arr[ind]) << endl;
			return;
		}
		if (arr[ind] == arr[ind + 1]) {
			ind += 2;
			continue;
		}

		vector<pair<int, int>> kek;
		ind++;
		int was = ind;
		bool can = false;

		while (ind != n) {
			if (kek.size() == 1 && kek[0].first == arr[was - 1]) {
				//ind++;
				can = true;
				break;
			}
			if (kek.size() == 0 || kek.back().first != arr[ind]) {
				kek.push_back(make_pair(arr[ind], 1));
			} else {
				kek.back().second++;
			}
			/*for (auto g: kek) {
				cout << g.first << " " << g.second << endl;
			}
			cout << endl;*/
			while (kek.back().second == p) {
				int a = kek.back().first + 1;
				kek.pop_back();
				if (kek.size() == 0 || kek.back().first != a) {
					kek.push_back(make_pair(a, 1));
				} else {
					kek.back().second++;
				}
			}
			/*for (auto g: kek) {
				cout << g.first << " " << g.second << endl;
			}
			cout << endl << endl << endl;*/
			ind++;
		}
		if (!can) {
			int a = pow(p, arr[was - 1]);
			for (int i = was; i < n; i++) {
				a -= pow(p, arr[i]);
			}
			a += MOD * 1000000LL;
			cout << a % MOD << endl;
			return;
		} else {
			//cout << ind;
		}
	}
	cout << 0 << endl;
	return;

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t != 0) {
    	t--;
    	solve();
    }
}