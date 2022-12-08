#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;


typedef long long ll;

const ll INF = 1e18;

bool is_tr(string st) {
	for (int i = 0; i < st.size() / 2; i++) {
		if (st[i] != st[st.size() - i - 1]) {
			return false;
		}
	}
	return true;
}


int main() {
	int n;
	cin >> n;
	string st;
	for (int i = 0; i < n; i++) {
		cin >> st;
		if (!is_tr(st)) {
			cout << st << endl;
		}
		else {
			int t1 = -1;
			for (int i = 0; i < st.size() - 1; i++) {
				if (st[i] != st[i + 1]) {
					t1 = i;
				}
			}
			if (t1 == -1) {
				cout << -1 << endl;
			}
			else {
				for (int i = 0; i < st.size(); i++) {
					if (i == t1 + 1) cout << st[i - 1];
					else if (i == t1) cout << st[i + 1];
					else cout << st[i];
				}
				cout << endl;
			}
		}
	}
	//system("pause");
	return 0;
}