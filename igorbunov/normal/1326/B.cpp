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
    vector<int> b(n + 1);

    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }

    int now = 0LL;

    arr[0] = b[0];
    now = b[0];

    for (int i = 1; i < n; i++) {
    	//if (b[i] >= 0) {
    		arr[i] = now + b[i];
    	//}
    	now = max(now, arr[i]);
    }

    for (int i = 0; i < n; i++) {
    	cout << arr[i] << " ";
    }
}