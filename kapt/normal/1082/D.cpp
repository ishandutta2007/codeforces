#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;
int arr[maxn];

main() {
    int n;
    cin >> n;
    int b = 0, a1 = 0;
    vector<int> lists, nlists;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] >= 2) {
            nlists.push_back(i);
            a1++;
        } else {
            lists.push_back(i);
            b++;
        }
    }
    vector<pair<int, int>> ansarr;
    for (int i = 1; i < a1; ++i) {
        ansarr.push_back({nlists[i] + 1, nlists[i - 1] + 1});
    }
    int ans = ansarr.size();
    int now = 0;
    if (a1 == 0) {
        cout << "NO";
        return 0;
    }
    bool f1 = false, f2 = false;
    for (int i = 0; i < b; ++i) {
        while (a1 > 1 && ((now == 0 && arr[nlists[now]] == 1) || (now == a1 - 1 && arr[nlists[now]] == 1) || (now != 0 && now != a1 - 1 && arr[nlists[now]] == 2))) {
            if (now != 0 && now != a1 - 1) {
                now++;
                if (now == a1 - 1) {
                    now = a1;
                    break;
                }
            }
            if (now == a1 - 1) {
                now = 1;
            }
            if (now == a1 - 1) {
                now = a1;
                break;
            }
            if (now == 0) {
                now = a1 - 1;
            }
            if (now == 0) {
                now = a1;
                break;
            }

        }
        if (now == a1) {
            cout << "NO";
            return 0;
        }
        if (!f2 && f1 && now == 0 && arr[nlists[a1 - 1]] > 1) {
            f2 = true;
            ans++;
            ansarr.push_back({nlists[a1 - 1] + 1, lists[i] + 1});
            arr[nlists[a1 - 1]]--;
            continue;
        }
        if (!f1 && now == 0) {
            ans++;
            f1 = true;
        } else if (!f2 && now == a1 - 1) {
            ans++;
            f2 = true;
        }

        ansarr.push_back({nlists[now] + 1, lists[i] + 1});
        arr[nlists[now]]--;
        if (arr[nlists[now]] < 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES " << ans << endl << ansarr.size() << endl;
    for (auto elem : ansarr) {
        cout << elem.first << " " << elem.second << endl;
    }
    return 0;
}