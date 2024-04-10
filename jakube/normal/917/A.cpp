#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int cur_min = 0;
        int cur_max = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '(') {
                cur_min++;
                cur_max++;
            }
            if (s[j] == ')') {
                cur_min--;
                cur_max--;
            }
            if (s[j] == '?') {
                cur_min--;
                cur_max++;
            }
            cur_min = max(0, cur_min);
            if (cur_max < 0)
                break;

            if ((j - i) % 2) {
                if (cur_min == 0)
                    cnt++;
            }
        }
    }
    cout << cnt << '\n';
}