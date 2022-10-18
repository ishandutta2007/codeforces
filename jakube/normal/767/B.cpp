#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long ts, tf, t;
    cin >> ts >> tf >> t;
    int n;
    cin >> n;
    vector<long long> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }
    sort(people.begin(), people.end());
    
    long long best = ts;
    long long best_time = 0;

    if (t == 0 || n == 0) {
        cout << ts << endl;
        return 0;
    }

    long long currently = ts;
    for (int i = 0; i < n; i++) {
        long long p = people[i];

        if (currently < p) {
            // try coming at timepoint currently
            if (currently + t <= tf) {
                best = 0;
                best_time = currently;
            }

            currently = p + t;
        } else {
            if (currently - (p - 1) < best && currently + t <= tf) {
                best = currently - (p - 1);
                best_time = p - 1;
            }

            currently += t;
        }
    }

    if (currently + t <= tf) {
        best = 0;
        best_time = currently;
    }

    cout << best_time << endl;

    return 0;
}