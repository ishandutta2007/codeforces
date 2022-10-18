#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    
    int best = std::numeric_limits<int>::max();
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            int cnt = abs(x) + abs(y);
            long long start = b[0] + x;
            long long sec = b[1] + y;
            long long d = sec - start;
            for (int i = 2; i < n; i++) {
                auto diff = abs(start + d*i - b[i]);
                if (diff <= 1) {
                    cnt += diff;
                } else {
                    cnt = std::numeric_limits<int>::max();
                    break;
                }
            }
            best = min(best, cnt);
        }
    }

    if (best == std::numeric_limits<int>::max()) 
        cout << -1 << '\n';
    else
        cout << best << endl;
}