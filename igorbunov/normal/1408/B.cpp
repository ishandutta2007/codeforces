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
    vector<int> arr(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    	s.insert(arr[i]);
    }
    int m = s.size();
    if (k == 1 && m > 1) {
    	cout << -1 << endl;
    	return;
    }
    if (m == 1) {
    	cout << 1 << endl;
    	return;
    }
    //cout << m - 1 << " " << k - 1 << endl;
    cout << (m - 2) / (k - 1) + 1 << endl;

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