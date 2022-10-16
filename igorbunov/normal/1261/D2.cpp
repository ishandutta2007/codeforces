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

int MOD = 998244353;

vector<int> f(400003);
vector<int> f1(400003);
 
int st(int a, int v) {
    if (v == 0) {
        return 1;
    }
 
    if (v % 2 == 0) {
        int c = st(a, v / 2);
        return (c * c) % MOD;
    } else {
        return (st(a, v - 1) * a) % MOD;
    }
}
 
void fill() {
    f[0] = 1;
    for (int i = 1; i <= 400000; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }
 
    for (int i = 0; i <= 400000; i++) {
        f1[i] = st(f[i], MOD - 2);
    }
}
 
 
int c(int n, int k) {
    return (((f[n] * f1[k]) % MOD) * f1[n - k]) % MOD;
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

    vector<int> st_2(n + 1);
    st_2[0] = 1;
    for (int i = 1; i <= n; i++) {
    	st_2[i] = st_2[i - 1] * 2;
    	st_2[i] %= MOD;
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


    int ans = 0;

    for (int i = 0; i <= arr1.size(); i++) {
    	int now = c(arr1.size(), i);
    	now *= st2[i];
    	now %= MOD;
    	int kek = st_2[arr1.size() - i];
    	if ((arr1.size() - i) % 2 == 0) {
    		kek -= c(arr1.size() - i, (arr1.size() - i) / 2);
    	}
    	while (kek < 0) {
    		kek += MOD;
    	}
    	kek *= f1[2];
    	kek %= MOD;
    	now *= kek;
    	now %= MOD;

    	ans += now;
    	ans %= MOD;
    }

    ans *= st[n - arr1.size()];
    ans %= MOD;

    while (ans < 0) {
    	ans += MOD;
    }
    cout << ans;
}