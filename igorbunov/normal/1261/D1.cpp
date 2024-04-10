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

int c[2002][2002];

int MOD = 998244353;

void fill() {
	for (int i = 0; i < 2002; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= MOD;
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill();

    int n, k;
    cin >> n >> k;
    vector<int> st(n + 1);
    st[0] = 1;
    for (int i = 1; i <= n; i++) {
    	st[i] = st[i - 1] * k;
    	st[i] %= MOD;
    }

    vector<int> st2(n + 1);
    st2[0] = 1;
    for (int i = 1; i <= n; i++) {
    	st2[i] = st2[i - 1] * (k - 2);
    	st2[i] %= MOD;
    }
    //return 0;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
    	cin >> arr[i];
    }
    vector<int> arr1;
    arr1.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
    	if (arr[i] != arr1.back()) {
    		arr1.push_back(arr[i]);
    	}
    }

    if (arr1.size() == 1 || k == 1) {
    	cout << 0;
    	return 0;
    }
    if (arr1[0] == arr1.back() && arr1.size() > 1) {
    	arr1.pop_back();
    }

    for (int i = 0; i < arr1.size(); i++) {
    	//cout << arr1[i] << " ";
    }
    //return 0;

    int ans = 0;

    for (int i = 0; i <= arr1.size(); i++) {
    	for (int j = 0; j <= arr1.size() - i; j++) {
    		int first = j;
    		int second = arr1.size() - i - j;

    		if (second <= first) {
    			continue;
    		}

    		//cout << first << " " << second << endl;
    		int now = c[arr1.size()][i];
    		now *= st2[i];
    		now %= MOD;
    		now *= c[arr1.size() - i][first];
    		now %= MOD;
    		ans += now;
    		ans %= MOD;
    	}
    }

    ans *= st[n - arr1.size()];
    ans %= MOD;
    cout << ans;
}