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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<char>> ans(n, vector<char>(m));
	int sum1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			arr[i][j] = (c == 'R');
			sum1 += arr[i][j];
		}
	}



	vector<char> preob(62);

	for (int i = 0; i < 10; i++) {
		preob[i] = '0' + i;
	}

	for (int i = 0; i < 26; i++) {
		preob[i + 10] = char('a' + i);
	}

	for (int i = 0; i < 26; i++) {
		preob[i + 36] = char('A' + i);
	}
	int count1 = sum1 % k;
	int kk1 = sum1 / k + 1;
	int kk2 = sum1 / k;
	int now = 0;

	int now_ans = 0;

	int now_r = 0;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				ans[i][j] =  preob[now_ans];
				now_r += arr[i][j];

				//cout << "A" << now << " " << count1
				if (now >= count1) {
					//cout << "AA";
					if (now_r == kk2) {
						now_r = 0;
						now_ans++;
						if (now_ans == k) {
							//cout << "A";
							now_ans--;
						}
						//cout << "a)";
						//count1++;
						now++;
					}
				} else {
					if (now_r == kk1) {
						now_r = 0;
						now_ans++;
						if (now_ans == k) {
							now_ans--;
						}
						//count1++;
						now++;
					}
				}
			}
		} else {
			for (int j = m - 1; j >= 0; j--) {
				ans[i][j] = preob[now_ans];
				now_r += arr[i][j];

				//cout << "A" << now << " " << count1
				if (now >= count1) {
					//cout << "AA";
					if (now_r == kk2) {
						now_r = 0;
						now_ans++;
						if (now_ans == k) {
							//cout << "A";
							now_ans--;
						}
						//cout << "a)";
						//count1++;
						now++;
					}
				} else {
					if (now_r == kk1) {
						now_r = 0;
						now_ans++;
						if (now_ans == k) {
							now_ans--;
						}
						//count1++;
						now++;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	solve();
    }
}