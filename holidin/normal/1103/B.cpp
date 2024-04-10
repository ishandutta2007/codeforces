#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e9;
const int maxn = 1e9;

int main() {
    string s;
    char c;
    int i, j, q, tr, top = 0, x;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true) {
        cin >> s;
        if (s != "start")
            return 0;
        x = 1;
        for (i = 0; x * 2 < maxn; ++i) {
            cout << "? " << x - 1 << ' ' << 2 * x - 1 << endl;
            cin >> s;
            if (s == "x")
                break;
            x *= 2;
        }
        int t = min(x * 2, maxn);
        while (t - x > 0) {
            int mid = (x + t + 1) / 2;
            cout << "? " << x - 1 << ' ' << mid - 1 << endl;
            cin >> s;
            if (s == "x")
                t = mid - 1;
            else
                x = mid;
        }
        cout << "! " << t << endl;
    }
}