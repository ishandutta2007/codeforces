#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, A, B;
    cin >> n >> A >> B;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin() + 1, s.end());
    long long sum = accumulate(s.begin(), s.end(), 0);
    int idx = n;
    while (s[0] * A < sum * B)
        sum -= s[--idx];
    cout << n - idx << endl;
}