#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<int>> divisors(200'001);
    for (int i = 1; i < divisors.size(); i++) {
        for (int j = i; j < divisors.size(); j+=i) {
            divisors[j].push_back(i);
        }
    }

    int n;
    cin >> n;
    vector<long long> v(n + 1, 0);
    for (int i = 2; i <= n; i += 2) {
        cin >> v[i];
    }

    long long sum = 0;
    for (int i = 2; i <= n; i+=2) {
        long long sum2 = sum;
        sum += v[i];
        int cur = v[i];
        long long best_x = -1;
        long long best_y = -1;
        for (int d : divisors[cur]) {
            int pl = d + cur / d;
            int mi = abs(d - cur / d);
            if (pl % 2 || mi % 2)
                continue;
            long long y = pl / 2;
            long long x = mi / 2;
            if (x * x > sum2) {
                if (best_x == -1 || y < best_y) {
                    best_x = x;
                    best_y = y;
                }
            }
        }
        if (best_x == -1) {
            cout << "No" << '\n';
            return 0;
        }
        v[i-1] = best_x * best_x - sum2;
        sum += v[i-1];
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        cout << v[i+1] << ' ';
    }
    cout << '\n';
    // for (int i = 0; i < n; i++) {
    //     v[i+1] += v[i];
    //     cout << v[i+1] << ' ';
    // }
    // cout << '\n';
}