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

using namespace std;

typedef long long ll;

ll INF = 4e18;
ll INFi = 2e9;
long double eps = 1e-6;
ll mod = 1e9 + 7;

vector<int> sm(vector<int> a, vector<int> b) {
	int k = 0;
	vector<int> ans;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < max(a.size(), b.size()); i++) {
		int t = (i < a.size() ? (a[i]) : 0) + (i < b.size() ? (b[i]) : 0) + k;
		k = 0;
		//cout << t << endl;
		ans.push_back(t % 10);
		k = t / 10;
	}
	if (k > 0) ans.push_back(k);
	//cout << "jopa\n";
	//for (int i : ans) cout << i;
	//cout << endl;
	reverse(ans.begin(), ans.end());
	return ans;
}

string st;

vector<int> subs(int l, int r) {
	vector<int> an(r - l + 1);
	for (int i = 0; i < (r - l + 1); i++) {
		an[i] = st[l + i] - '0';
	}
	//cout << l << " " << r << endl;
	//for (int i : an) cout << i;
	//cout << endl;
	return an;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);

	int l;
	cin >> l;
	cin >> st;
	int ind = l / 2;
	while (st[ind] == '0') ind--;
	int ind2 = ind + 1;
	vector<int> f1 = sm(subs(0, ind - 1), subs(ind, l - 1));
	while (ind2 < st.size() && st[ind2] == '0') ind2++;
	if (ind2 == st.size()) {
		for (int i : f1) cout << i;
		cout << endl;
		return 0;
	}
	vector<int> f2 = sm(subs(0, ind2 - 1), subs(ind2, l - 1));
	/*for (int i : f1) cout << i;
	cout << endl;
	for (int i : f2) cout << i;
	cout << endl;*/
	if (f1.size() < f2.size() || (f1.size() == f2.size() && f1 <= f2)) {
		for (int i : f1) cout << i;
		cout << endl;
	}
	else {
		for (int i : f2) cout << i;
		cout << endl;
	}
	return 0;
}