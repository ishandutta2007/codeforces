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

int P = 1000000007LL;

vector<int> fact(2000);
int c[1002][1002];

void init() {
	fact[0] = 1LL;
	for (int i = 1; i <= 1000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= P;
	}
	for (int i = 0; i <= 1000; i++) {
		for (int j = i; j <= 1000; j++) {
			if (i == 0) {
				c[i][j] = 1;
			} else {
				c[i][j] = c[i][j - 1] + c[i - 1][j - 1];
				c[i][j] %= P;
			}
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int n, x, pos;
    cin >> n >> x >> pos;
    int cnt1 = 0;
    int cnt2 = 0;
    int l = 0;
    int r = n;
    while (l < r) {
    	int m = (l + r) / 2;
    	if (pos >= m) {
    		if (pos != m) {
    			cnt1++;
    		}
    		l = m + 1;
    	} else {
    		cnt2++;
    		r = m;
    	}
    }
    int cnt3 = n - cnt1 - cnt2 - 1;
    int ans = 1LL;
    ans *= fact[cnt3];
    ans %= P;
    ans *= c[cnt1][x - 1];
    ans %= P;
    ans *= fact[cnt1];
    ans %= P;
    ans *= c[cnt2][n - x];
    ans %= P;
    ans *= fact[cnt2];
    ans %= P;
    cout << ans;
}