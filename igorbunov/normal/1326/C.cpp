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

int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    vector<int> e(n);

    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    	p[i]--;
    	e[p[i]] = i;
    }

    int ans1 = 0;
    vector<int> now;

    for (int i = n - 1; i > n - 1 - k; i--) {
    	ans1 += i + 1;
    	now.push_back(e[i]);
    }
    sort(now.begin(), now.end());
    int ans2 = 1LL;
    for (int i = 1; i < now.size(); i++) {
    	ans2 *= (now[i] - now[i - 1]);
    	ans2 %= mod;
    }

    cout << ans1 << " " << ans2 << endl;
}