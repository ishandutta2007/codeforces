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
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    vector<string> arr1(m);

    for (int j = 0; j < m; j++) {
    	cin >> arr1[j];
    }
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
    	int y;
    	cin >> y;
    	y--;
    	string ans = arr[y % n] + arr1[y % m];

    	cout << ans << endl;
    }
}