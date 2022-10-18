#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int m = 0;
    vector<int> changed(2, 0);
    vector<int> start(2, 0);
    for (int i = 0; i < s.size(); ++i) {
        int j = s[i] - 'a';
        if (changed[j]  == k) {
            while (s[start[j]] - 'a' == 1 - j) start[j]++;
            start[j]++;
        }
        else changed[j]++;
        m = max(m, i + 1 - start[j]);
        m = max(m, i + 1 - start[1-j]);
    }

    cout << m << endl;

    return 0;
}