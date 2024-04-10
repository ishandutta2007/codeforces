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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    if (n == 1) {
    	cout << 1 << " " << 1 << endl;
    	cout << -arr[0] << endl;
    	arr[0] = 0;
    	cout << 1 << " " << 1 << endl;
    	cout << -arr[0] << endl;
    	arr[0] = 0;
    	cout << 1 << " " << 1 << endl;
    	cout << -arr[0] << endl;
    	arr[0] = 0;
    } else {
    	cout << 1 << " " << n << " " << endl;
    	for (int i = 0; i < n - 1; i++) {
    		cout << -1 * arr[i] * n << " ";
    	}
    	cout << 0;
    	cout << endl;
    	cout << 1 << " " << n - 1 << endl;
    	for (int i = 0; i < n - 1; i++) {
    		cout << arr[i] * (n - 1) << " ";
    	}
    	cout << endl;
    	cout << n << " " << n << endl;
    	cout << -arr[n - 1] << endl;
    }
}