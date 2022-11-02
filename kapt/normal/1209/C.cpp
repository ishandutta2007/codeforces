#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(arr, arr + n + 1, 0);
        string s;
        cin >> s;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({s[i] - '0', i});
        }
        sort(arr.begin(), arr.end());
        vector<char> ans(n, '0');
        int ls = arr.back().second;
        int k = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i].second <= ls && arr[i].first >= k) {
                ans[arr[i].second] = '2';
                ls = arr[i].second;
            } else if (arr[i].second > ls && k == -1) {
                k = arr[i].first;
                ans[arr[i].second] = '1';
            } else {
                ans[arr[i].second] = '1';
            }
        }
        int lst = '0';
        bool f = false;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == '1' && s[i] < lst) {
                cout << '-' << endl;
                f = true;
                break;
            }
            if (ans[i] == '1') {
                lst = s[i];
            }
        }
        if (!f) {
            for (auto elem : ans) {
                cout << elem;
            }
            cout << endl;
        }
    }
    return 0;
}