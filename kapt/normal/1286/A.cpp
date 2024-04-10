#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
vector<int> arr;

int get(vector<int> arr) {
    int n = arr.size();
    int last = 0;
    vector<int> even;
    vector<int> odd;
    int ce = (n - 1) / 2, co = (n - 2) / 2;
    int li = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            int x = arr[i] % 2;
            if (x == 0) {
                x = 2;
                if (i != 0 && i != n - 1) {
                    co--;
                }
            } else {
                if (i != 0 && i != n - 1) {
                    ce--;
                }
            }
            if (x & last) {
                if (x == 1) {
                    even.push_back(i - li - 1);
                } else {
                    odd.push_back(i - li - 1);
                }
                ans++;
            }
            ans++;
            last = x;
            li = i;
        }
    }
    ans--;
    if (co + ce == n - 2) {
        if (n == 3) {
            return 0;
        } else {
            return 1;
        }
    }
    sort(even.begin(), even.end());
    for (auto elem : even) {
        if (ce >= elem) {
            ce -= elem;
            ans -= 2;
        }
    }
    sort(odd.begin(), odd.end());
    for (auto elem : odd) {
        if (co >= elem) {
            co -= elem;
            ans -= 2;
        }
    }
    return ans;
}

main() {
    int n;
    cin >> n;
    arr.resize(n + 2);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i + 1];
    }
    int ans = 1e9;
    for (int i = 1; i < 3; ++i) {
        for (int j = 1; j < 3; ++j) {
            arr[0] = i;
            arr[n + 1] = j;
            ans = min(ans, get(arr));
        }
    }
    cout << ans;
    return 0;
}