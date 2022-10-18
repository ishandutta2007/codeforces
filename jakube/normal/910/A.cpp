#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    int cur = 0;
    int cnt = 0;
    while (cur != n - 1) {
        int last = cur;
        for (int i = cur + 1; i <= min(cur + d, n-1); i++) {
            if (s[i] == '1')
                last = i;
        }
        if (cur == last) {
            cout << -1 << '\n';
            return 0;
        }
        cur = last;
        cnt++;
    }
    cout << cnt << endl;
}