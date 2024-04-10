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
	int n, k;
	cin >> n >> k;
	//cout << n << " " << k << endl;
	vector<int> v(n);
 
	vector<int> a(n);
 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	int now = k;
 
	while (now < 1000000000000000001LL) {
		int cnt = 0;
		int ind = -1;
 
		for (int i = 0; i < n; i++) {
			if (v[i] % now != a[i] % now) {
				cnt++;
				ind = i;
			}
		}
 
		if (cnt > 1) {
			cout << "NO\n";
			return;
		}
 
		if (ind != -1) {
			v[ind] += (now / k);
		}
		now *= k;
	}
 
	for (int i = 0; i < n; i++) {
		//cout << v[i] << " ";
		if (v[i] != a[i]) {
			cout << "NO\n";
			return;
		}
	}
 
	//cout << endl;
 
	cout << "YES\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}