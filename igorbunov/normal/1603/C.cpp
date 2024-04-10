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
#define int long long

int solve1(vector<int> arr){
    int n = arr.size();
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        int kek = (arr[i] - 1) / (arr[i + 1]);
        ans += kek;
        arr[i] /= (kek + 1);
    }
    return ans;
}

int get(vector<int> arr,int l, int r) {
    vector<int> now;
    for (int i = l; i <= r; i++) {
        now.push_back(arr[i]);
    }
    return solve1(now);
}

int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<pair<int, int>> now(n);
    for (int i = 0; i < n; i++) {
        now[i] = make_pair(arr[i], arr[i]);
    }
    int ans = 0;
    vector<int> pre(n);
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (now[j].second <= now[j + 1].first) {
                break;
            } else {
                int val = arr[j];
                int need = now[j + 1].first;
                int kek = (val - 1) / (need);
                ans += ((((kek - pre[j]) * (n - i)) % MOD) * (j + 1)) % MOD;
                ans %= MOD;
                pre[j] = kek;
                kek++;

                now[j].first = val / kek;
                now[j].second = (val - 1) / kek + 1;
            }
        }
    }
    cout << ans << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}