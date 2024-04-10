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

void solve() {
	string a, b, c;
	cin >> a >> b >> c;

	bool can = true;

	for (int i = 0; i < a.size(); i++) {
		if ((c[i] != a[i]) && (c[i] != b[i])) {
			//cout << i;
			//cout << a[i] << " " << b[i] << " " << c[i];
			can = false;
			break;
		}
	}

	if (can) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	solve();
    }
}