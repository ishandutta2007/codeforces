#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    string s;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long long l = 1, r = n + 1;
    while (true) {
        long long x = l + (rand() + rand()) % (r - l);
        cout << x << ' ' << x << endl;
        cin >> s;
        if (s == "Yes")
            return 0;
        x = (l + r) / 2;
        cout << 1 << ' ' << min(n, x + 10) << endl;
        cin >> s;
        if (s == "Yes") {
            r = min(n + 1, x + 20);
            l = max((long long)1, l - 20);
        } else {
            l = max((long long)1, x - 10);
            r = min(n + 1, r + 20);
        }
    }
}