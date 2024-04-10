#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <bitset>
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

#define data NE_data
#define rank NE_rank
#define endl '\n'

const int MAXN = 20000000;
long long dp[MAXN + 1];

int cnt[MAXN + 1];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);


    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] == 1) {
            continue;
        }

        bool bad = false;
        for (int j = 2; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                bad = true;
                cnt[j]++;

                if (j * j != arr[i]) {
                    cnt[arr[i] / j]++;
                }
            }
        }
        cnt[arr[i]]++;
    }

    dp[1] = n;

    for (long long i = 2; i <= MAXN; i++) {
        dp[i] = max(dp[i], dp[1] + (i - 1) * cnt[i]);
    }
    long long ans = dp[1];
    for (int i = 2; i <= MAXN; i++) {

        if (dp[i] == 0) {
            continue;
        }

        long long bobs = dp[i];
        for (long long j = i * 2; j <= MAXN; j += i) {
            if (cnt[j] == 0) {
                continue;
            }
            dp[j] = max(dp[j], bobs + (j - i) * cnt[j]);
        }
        ans = max(ans, dp[i]);

        //cout << i << " " << dp[i] << endl;
    }
    cout << ans;
}