#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

ll powe(int n, int k) {
	if (k == 0) return 1;
	return n * powe(n, k - 1);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
		
	string st;
	cin >> st;
	if (st.size() == 1) {
		cout << st << endl;
		return 0;
	}
	ll maxi = 0;
	ll cur = 1;
	if (st[0] == '1') maxi = powe(9, st.size() - 1);
	for (int i = 0; i < st.size(); i++) {
		if (st[i] == '0') break;
		maxi = max(maxi, cur *  (st[i] - '0' - 1) * powe(9, st.size() - i - 1));
		cur *= (st[i] - '0');
	}
	maxi = max(maxi, cur);
	cout << maxi << endl;
	//system("pause");
	return 0;
}