#include <bits/stdc++.h>
using namespace std;

typedef array<long long, 5> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    S solved = {{ 0 }};
    S score_v = {{ 0 }};
    S score_p = {{ 0 }};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int a;
            cin >> a;
            if (a >= 0) {
                solved[j]++;
                if (i == 0)
                    score_v[j] = 500 - 2 * a;
                if (i == 1)
                    score_p[j] = 500 - 2 * a;
            }
        }
    }

    for (int add = 0; add < 10000; add++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            int p = solved[j];
            int q = n + add;
            if (score_v[j] > 0 && score_v[j] < score_p[j]) {
                p += add;
            }

            int diff = score_v[j] - score_p[j];
            if (2 * p > q)
                sum += diff;
            else if (4 * p > q)
                sum += 2 * diff;
            else if (8 * p > q)
                sum += 3 * diff;
            else if (16 * p > q)
                sum += 4 * diff;
            else if (32 * p > q)
                sum += 5 * diff;
            else
                sum += 6 * diff;
        }

        if (sum > 0) {
            cout << add << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}