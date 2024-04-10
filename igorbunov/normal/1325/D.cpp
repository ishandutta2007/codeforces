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
    int v, u;
    cin >> v >> u;

    if (v > u) {
    	cout << -1;
    	return 0;
    }

    if (v == 0 && u == 0) {
    	cout << 0;
    	return 0;
    }

    if (v == u) {
    	cout << 1 << endl << v;
    	return 0;
    }

    vector<int> arr1(61);
    vector<int> arr2(61);

    vector<int> arr3(61);

    int ans1 = 0LL;
    int ans2 = 0LL;
    int ans3 = 0LL;

    for (int i = 0; i <= 60; i++) {
    	if (((1LL << i) & v) != 0) {
    		arr1[i] = 1;
    		ans1 += (1LL << i);
    	}
    }

    u -= v;

    if (u % 2 != 0) {
    	cout << -1;
    	return 0;
    }

    u /= 2;

    bool kek = true;


    for (int i = 0; i <= 60; i++) {
    	if (((1LL << i) & u) != 0) {
    		ans2 += (1LL << i);
    		if (arr1[i] != 0) {
    			kek = false;
    			ans3 += (1LL << i);
    		} else {
    			ans1 += (1LL << i);
    		}
    	}
    }

    if (kek) {
    	cout << 2 << endl << ans1 << " " << ans2;
    } else {
    	cout << 3 << endl << ans1 << " " << ans2 << " " << ans3;
    }

}