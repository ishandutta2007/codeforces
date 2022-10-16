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

int MOD = 1000000007LL;

int cnt[5001][5001];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> s(n);

    vector<int> total(5001);

    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    	total[s[i]]++;
    }

    vector<pair<int, int>> arr(m);

    vector<int> lol(5001);
    for (int i = 0; i < m; i++) {
    	cin >> arr[i].first >> arr[i].second;
    	lol[arr[i].first]++;


    	//cout << arr[i].first << " " << arr[i].second << endl;
    	cnt[arr[i].first][arr[i].second] = 1LL;
    }

    for (int i = 0; i < 5001; i++) {
    	for (int j = 1; j < 5001; j++) {
    		cnt[i][j] = cnt[i][j - 1] + cnt[i][j];
    	}
    }


    vector<int> now1(5001);

    int ans_val = 0LL;
    int ans = 1LL;

    for (int i = 0; i < 5001; i++) {
    	if (lol[i] > 0 && total[i] > 0) {

    		int cnt2 = 0LL;
    		for (int j = 0; j < m; j++) {
    			if (arr[j].first == i) {
    				if (arr[j].second <= total[i]) {
    					cnt2++;
    				}
    			}
    		}


    		if (cnt2 == 0LL) {
    			continue;
    		}
    		ans_val++;
    		ans *= cnt2;
    		ans %= MOD;
    	}
    }

    //cout << ans_val << " " << ans << endl;

    for (int i = 0; i < n; i++) {
    	now1[s[i]]++;
    	if ((cnt[s[i]][now1[s[i]]] - cnt[s[i]][now1[s[i]] - 1]) != 1) {
    		//cout << 0 << " " << 0 << endl;
    		continue;
    	}

    	int now_val = 1LL;
    	int now = 1LL;
    	for (int j = 0; j < 5001; j++) {
    		if (j != s[i]) {
    			int a = now1[j];
    			int b = total[j] - a;
    			if (a > b) {
    				swap(a, b);
    			}

    			if (cnt[j][b] >= 2 && cnt[j][a] >= 1) {
    				now_val += 2;
    				now *= ((cnt[j][b] * cnt[j][a]) - cnt[j][a]);
    				now %= MOD;
    				continue;
    			}
    			if (cnt[j][a] > 0) {
    				now_val++;
    				now *= 2LL;
    				now %= MOD;
    				continue;
    			}

    			if (cnt[j][b] > 0) {
    				now_val++;
    				now *= cnt[j][b];
    				now %= MOD;
    			}
    		} else {


    			int a = now1[j];
    			int b = total[j] - a;

    			if (a <= b) {
    				cnt[j][b]--;
    			}
    			if (cnt[j][b] > 0) {
    				now *= cnt[j][b];
    				now %= MOD;
    				now_val++;
    			}

    			if (a <= b) {
    				cnt[j][b]++;
    			}

    		}
    			
    	}

    	//cout << now_val << " " << now << endl;

    	if (now_val > ans_val) {
    		ans_val = now_val;
    		ans = now;
    		continue;
    	}
    	if (now_val == ans_val) {
    		ans += now;
    		ans %= MOD;
    	}

    }

    cout << ans_val << " " << ans;

}