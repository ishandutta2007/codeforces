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


struct  vertex {
	int next[26];
	int t;
	bool good = false;
};


vertex g[1000001];

vector<int> dp1(1000001, 100000000);

int now1 = 0;

void dfs(int v, int now) {
	if (g[v].good) {
		g[v].t = now1;
		dp1[v] = now1;
		now1++;
	} else {
		g[v].t = 100000000;
	}

	for (int i = 0; i < 26; i++) {
		if (g[v].next[i] != -1) {
			int u = g[v].next[i];
			dfs(u, now);
			dp1[v] = min(dp1[v], dp1[u]);
		}
	}
}

vector<int> dp(1000001, 1000000000LL);

void calc(int v, int now, int p = -1) {
	if (p != -1) {
		dp[v] = min(dp[v], dp[p] + 1);
	}

	if (g[v].good) {
		if (now < -100000000) {
			exit(1);
		}
		dp[v] = min(dp[v], now + g[v].t);
	} else {
	}



	now = min(now, dp[v] - dp1[v] + 1);


	for (int i = 0; i < 26; i++) {
		if (g[v].next[i] != -1) {
			int u = g[v].next[i];
			calc(u, now, v);
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < 26; i++) {
    	g[0].next[i] = -1;
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 26; j++) {
    		g[i + 1].next[j] = -1;
    	}
    	int p;
    	char c;
    	cin >> p >> c;
    	g[p].next[c - 'a'] = i + 1;
    }

    int k;
    cin >> k;

    vector<int> arr(k);

    for (int i = 0; i < k; i++) {
    	cin >> arr[i];
    	g[arr[i]].good = true;
    }

    dfs(0, 0);

    /*for (int i = 0; i <= n; i++) {
    	cout << i << " " << g[i].t << "\n";
    }

    cout << endl;

    for (int i = 0; i <= n; i++) {
    	cout << i << " " << dp1[i] << "\n";
    }

    cout << endl;*/

    dp[0] = 0;

    calc(0, 1000000000);

    /*for (int i = 0; i <= n; i++) {
    	cout << dp[i] << " ";
    }

    cout << endl;*/

    for (int i = 0; i < k; i++) {
    	cout << dp[arr[i]] << " ";
    }
}