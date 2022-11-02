#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template <typename hd, typename tl>
void chkmin(hd& a, tl b) {
    if (b < a) a = b;
}

template <typename hd, typename tl>
void chkmax(hd& a, tl b) {
    if (a < b) a = b;
}

const int MX = 200005;

int64 a[MX];
vector<pair<int64, int>> V;
vector<int> buf;

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int64 tot = 0, rlt = -LLONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
        V.push_back({a[i], i});
    }
    if (n == 1)
        cout << a[0] << endl;
    else if (n == 2)
        cout << -(a[0] + a[1]) << endl;
    else if (n == 3)
        cout << max(a[0] + a[1] - a[2], a[2] + a[1] - a[0]) << endl;
    else {
        sort(V.begin(), V.end());
        int s = 2 - n % 3;
        s = n - s;
        s %= 3;
        int c = 0;
        int64 cur = 0;
        while (s <= n) {
            while (c < s) cur += V[c++].first;
            if (abs(s * 2 - n) <= 1) {
                int64 tp = 0;
                buf.clear();
                for (int i = 0; i < s; i++) {
                    tp += V[i].first;
                    buf.push_back(V[i].second);
                }
                sort(buf.begin(), buf.end());
                bool ok = 0;
                for (int i = 0; i < buf.size() - 1; i++)
                    if (buf[i + 1] - buf[i] != 2) {
                        ok = 1;
                        break;
                    }
                if (ok)
                    rlt = max(rlt, tot - tp * 2);
                else
                    rlt =
                        max(rlt, tot - 2 * (tp - V[s - 1].first + V[s].first));
            } else
                rlt = max(rlt, tot - 2 * cur);
            s += 3;
        }
        cout << rlt << endl;
    }

    return 0;
}