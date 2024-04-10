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
	int n;
	cin >> n;
	vector<int> arr(n);
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) {
			a++;
		} else {
			b++;
		}
	}
	if (a >= b) {
		cout << a << endl;
		for (int i = 0; i < a; i++) {
			cout << 0 << " ";
		}
	} else {
		cout << ((b) / 2) * 2 << endl;
		for (int i = 0; i < ((b) / 2) * 2; i++) {
			cout << 1 << " ";
		}
	}
	cout << endl;
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