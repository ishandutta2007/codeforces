#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> psum(n+1, 0);
    for (int i = 0; i < n; i++)
        psum[i+1] = psum[i] + (s[i] == '0');

    int best = n;

    for (int i = 1; i <= n; i++)
    {
        if (s[i-1] == '1')
            continue;

        int l = 0, r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;

            int upper = min(n, i + m);
            int lower = max(1, i - m);

            int cur = psum[upper] - psum[lower - 1];
            if (cur >= k+1)
                r = m;
            else
                l = m;
        }
        
        best = min(best, r);
    }

    cout << best << endl;
}