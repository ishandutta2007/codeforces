#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define sq pair<pair<int, int>, pair<int, int>>
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second

const int inf = 1e10;

sq inters(sq a, sq b) {
    sq ans;
    ans.x1 = max(a.x1, b.x1);
    ans.y1 = max(a.y1, b.y1);
    ans.x2 = min(a.x2, b.x2);
    ans.y2 = min(a.y2, b.y2);
    return ans;
}

bool is_0(sq a) {
    return !(a.x1 <= a.x2 && a.y1 <= a.y2);
}

void print(sq a) {
    cout << a.x1 << " " << a.y1 << " " << a.x2 << " " << a.y2 << endl;
}

main() {
    int n;
    cin >> n;
    vector<sq> arr(n);
    int xi1, xi2, yi1, yi2;
    for (int i = 0; i < n; ++i) {
        cin >> xi1 >> yi1 >> xi2 >> yi2;
        arr[i] = {{xi1, yi1}, {xi2, yi2}};
    }
    sq now_int = {{-inf, -inf}, {inf, inf}};
    int ind1, ind2;
    int skip = 1;
    for (int i = 0; i <= n; ++i) {
        if (i == n - skip) {
            cout << now_int.x1 << " " << now_int.y1;
            return 0;
        }
        if (is_0(inters(now_int, arr[i]))) {
            int cnt = 0;
            int ind = -1;
            for (int j = 0; j < i; ++j) {
                if (is_0(inters(arr[i], arr[j]))) {
                    ind = j;
                    cnt++;
                }
            }
            if (cnt > 1) {
                skip = 0;
                continue;
            } else {
                ind1 = ind;
                ind2 = i;
                break;
            }
        }
        now_int = inters(now_int, arr[i]);
    }
    now_int = {{-inf, -inf}, {inf, inf}};
    for (int i = 0; i < n; ++i) {
        if (i == ind1) {
            continue;
        }
        now_int = inters(now_int, arr[i]);
    }
    if (!is_0(now_int)) {
        cout << now_int.x1 << " " << now_int.y1;
        return 0;
    }
    now_int = {{-inf, -inf}, {inf, inf}};
    for (int i = 0; i < n; ++i) {
        if (i == ind2) {
            continue;
        }
        now_int = inters(now_int, arr[i]);
    }
    if (!is_0(now_int)) {
        cout << now_int.x1 << " " << now_int.y1;
        return 0;
    }
    return 0;
}