#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n);
    for (int idx = 0; idx < n; idx++)
        cin >> a[idx];
    vector<int> b(m);
    for (int idx = 0; idx < m; idx++)
        cin >> b[idx];
    
    set<int> s(b.begin(), b.end());
    vector<int> numbers(s.begin(), s.end());

    for (int &x : a) {
        auto it = lower_bound(numbers.begin(), numbers.end(), x);
        if (it != numbers.end() && *it != x) it = numbers.end();
        x = it - numbers.begin();
    }
    for (int &x : b) {
        auto it = lower_bound(numbers.begin(), numbers.end(), x);
        if (it != numbers.end() && *it != x) it = numbers.end();
        x = it - numbers.begin();
    }

    vector<int> result;

    int C = numbers.size();

    vector<int> cntB(numbers.size() + 1, 0);
    for (int i : b)
        cntB[i]++;

    long long ma = (long long)(m-1) * (long long)p;
    for (int I = n - 1; I > max(-1, n - 1 - p); I--) {
        if (I < ma) continue;

        int len = 0;
        int zeros = 0;

        for (int j = I; j + m * p >= 0; j -= p) {
            if (j >= 0) {
                int num = a[j];
                if (num != C && cntB[num] == 0) {
                    zeros--;
                }
                cntB[num]--;
                if (num != C && cntB[num] == 0) {
                    zeros++;
                }
            }
            len++;
            if (len > m) {
                int num = a[j + m * p];
                if (num != C && cntB[num] == 0) {
                    zeros--;
                }
                cntB[num]++;
                if (num != C && cntB[num] == 0) {
                    zeros++;
                }
            }

            if (len >= m && zeros == C)
                result.push_back(j);
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int idx : result) {
        cout << idx + 1 << ' ';
    }
    cout << endl;



    return 0;
}