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

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(x,n) for(int x = 0; x < n; ++x)
 
typedef pair<int, int> pii;


 
//#pragma GCC_OPTIMIZE("ofast")


#define int long long
#define endl "\n"

int dp[2000][2000];
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		dp[i][j] = (1LL << 30);

    		int c = a[i][j] != 'a';
		    if (!i && !j) {
		    	dp[i][j] = c;
		    	continue;
		    }
		    if (i) {
		    	dp[i][j] = min(dp[i][j], dp[i - 1][j] + c);
		    }
		    if (j) {
		    	dp[i][j] = min(dp[i][j], dp[i][j - 1] + c);
		    }
		}
  }
 
  int best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
    	if (dp[i][j] <= k) {
    		best = max(best, i+j);
    	}
	}
  }
 
  set<pii> good[2];
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j < n; j++) {
		if (dp[i][j] <= k && i+j == best) {
			good[0].insert({i, j});
		}
	}
  }
 
  string ans(best + 1, 'a');
 
  if (good[0].empty()) {
    ans = "";
    ans += a[0][0];
    good[0].insert({0, 0});
    best = 0;
  }
 
  int cur = 0, next = 1;
  for (int it = best + 1; it < 2*n - 1; it++) {
    int best_c = 999;
 
    for (auto &p: good[cur]) {
      if (p.first + 1 < n) {
        int c = a[p.first + 1][p.second];
        if (c < best_c) {
          best_c = c;
          good[next].clear();
        }
 
        if (c == best_c) {
          good[next].insert({p.first + 1, p.second});
        }
      }
      if (p.second + 1 < n) {
        int c = a[p.first][p.second + 1];
        if (c < best_c) {
          best_c = c;
          good[next].clear();
        }
 
        if (c == best_c) {
          good[next].insert({p.first, p.second + 1});
        }
      }
    }
 
    ans += best_c;
    swap(cur, next);
  }
 
  cout << ans << endl;
}