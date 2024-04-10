#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
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


#define data NE_data
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;
	set<string> data;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr[i] = s;
		data.insert(s);
	}
	for (auto s: data) {
		if (s.size() == 1) {
			cout << "YES\n";
			return;
		}
		if (s[0] == s[s.size() - 1]) {
			cout << "YES\n";
			return;
		}

		{
			string need = s;
			reverse(need.begin(), need.end());
			if (data.find(need) != data.end()) {
				cout << "YES\n";
				return;
			}
		}


		/*if (s.size() == 3) {
			string need = "";
			need += s[1];
			need += s[0];
			if (data.find(need) != data.end()) {
				cout << "YES\n";
				return;
			}

			need = "";
			need += s[2];
			need += s[1];
			if (data.find(need) != data.end()) {
				cout << "YES\n";
				return;
			}
		}*/
	}

	data.clear();
	for (int i = 0; i < n; i++) {
		string s = arr[i];
		string need = "";
		need += s[2];
		need += s[1];
		if (data.find(need) != data.end()) {
			cout << "YES\n";
			return;
		}
		data.insert(s);
	}
	data.clear();
	for (int i = n - 1; i >= 0; i--) {
		string s = arr[i];
		string need = "";
		need += s[1];
		need += s[0];
		if (data.find(need) != data.end()) {
			cout << "YES\n";
			return;
		}
		data.insert(s);
	}
	cout << "NO\n";
}
signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}