#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string genome = "ACTG";
    int best = std::numeric_limits<int>::max();
    for (int offset = 0; offset + 3 < n; offset++) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            char c = s[offset + i];
            char d = c;
            int a = 0;
            while (d != genome[i]) {
                d--;
                if (d == 'A' - 1)
                    d = 'Z';
                a++;
            }
            d = c;
            int b = 0;
            while (d != genome[i]) {
                d++;
                if (d == 'Z' + 1)
                    d = 'A';
                b++;
            }
            count += min(a, b);
        }
        best = min(best, count);
    }
    cout << best << endl;
}