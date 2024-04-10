#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    vector<long long> shifts(64, 0);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        long long X;
        cin >> X;
        int level = 63 - __builtin_clzll(X);
        if (t == 1) {
            long long K;
            cin >> K;
            shifts[level + 1] -= 2*K;
            shifts[level + 1] %= 1LL << (level + 1);
            shifts[level] += K;
            shifts[level] %= 1LL << level;
        } else if (t == 2) {
            long long K;
            cin >> K;
            shifts[level] += K;
            shifts[level] %= 1LL << level;
        } else {
            while (X) {
                cout << X << " ";
                long long offset = 1LL << level;
                X -= offset;

                X += shifts[level];
                X %= offset;
                if (X < 0)
                    X += offset;

                X += offset;
                X /= 2;
                level--;
            }
            cout << "\n";
        }
    }
}