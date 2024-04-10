#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int result = 0;
    map<int, int> m;
    m[0] = -1;
    int balance = 0;
    for (int i = 0; i < n; i++) {
        balance += (2 * (s[i] - '0') - 1);
        if (m.count(balance)) {
            result = max(result, i - m[balance]);
        } else {
            m[balance] = i;
        }
    }
    cout << result << endl;
}