#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 200000 + 10;

int n;
int64 a[N];

int getNext(int st) {
    int64 tmp = st;
    vector<pair<int64, int> > vec;
    for (; tmp < n && vec.size() < 2; tmp++) {
        if (a[tmp] > 0) {
            vec.push_back(make_pair(a[tmp], tmp));
        }
    }
    if (vec.size() != 2) return n;

    int64 v1 = vec[0].first, t1 = vec[0].second;
    int64 v2 = vec[1].first, t2 = vec[1].second;
    if ((v2 - v1) % (t2 - t1) == 0) {
        int64 d = (v2 - v1) / (t2 - t1);
        tmp = v1;
        int flag = true;
        for (int i = t1 - 1; i >= st; --i) {
            tmp -= d;
            if (tmp <= 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            st = t2;
            tmp = v2;
            for (; st < n && tmp > 0;) {
                if (a[st] > 0 && a[st] != tmp) break;
                ++st;
                tmp += d;
            }
            return st;
        }
    }
    return t2;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", a + i);
    }
    int ret = 0;
    int tmp = 0;
    for (; tmp != n;) {
        ++ret;
        tmp = getNext(tmp);
    }
    cout << ret << endl;
}

int main() {
    solve();
    return 0;
}