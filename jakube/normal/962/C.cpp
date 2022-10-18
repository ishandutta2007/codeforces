#include <bits/stdc++.h>
using namespace std;

int sqrt(long long x) {
    long long L = 0;
    long long R = std::numeric_limits<int>::max();
    while (L + 1 < R) {
        long long M = (L + R) / 2;
        if (M * M <= x)
            L = M;
        else
            R = M;
    }
    return L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    
    int res = n;
    for (int i = 0; i < (1 << n); i++) {
        int num = 0;
        int len = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                num = num * 10 + s[j] - '0';
                if (len || s[j] != '0')
                    len++;
            }
        }
        int sq = sqrt(num);
        if (sq * sq == num)
            res = min(res, n - len);
    }
    if (res == n)
        cout << -1 << endl;
    else
        cout << res << endl;
}