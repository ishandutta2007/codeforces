#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int smallest = v[0];
    for (int num : v) {
        smallest = min(num, smallest);
    }
    
    vector<int> primes;
    for (int d = 2; d * d <= smallest; d++) {
        if (smallest % d == 0) {
            primes.push_back(d);
            while (smallest % d == 0) {
                smallest /= d;
            }
        }
    }
    if (smallest > 1)
        primes.push_back(smallest);

    for (int p : primes) {
        bool b = true;
        for (int num : v) {
            if (num % p) {
                b = false;
                break;
            }
        }

        if (b) {
            cout << "YES" << endl;
            cout << 0 << endl;
            return 0;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) {
            if (i + 1 < n && v[i+1] % 2) {
                cnt++;
                v[i+1]++;
                i++;
            } else
                cnt += 2;
        }
    }

    cout << "YES" << endl;
    cout << cnt << endl;
}