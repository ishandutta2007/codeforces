#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> prime(1000000);
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    fill(prime.begin(), prime.begin() + 1000000, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < 1000000; i++) {
        if (prime[i]) {
            v.push_back(i);
            for (int j = i + i; j < 1000000; j += i) {
                prime[j] = 0;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n & 1) {
            if (n == 1)
                cout << "FastestFinger" << endl;
            else
                cout << "Ashishgup" << endl;
            continue;
        } else {
            if (n == 2) {
                cout << "Ashishgup" << endl;
                continue;
            }
            int k = n / 2;
            int ok = 1;
            for (int i = 0; i < v.size(); i++) {
                if (k % v[i] == 0 && k != v[i]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << "FastestFinger" << endl;
                continue;
            }
            while (n % 2 == 0) n /= 2;
            if (n == 1)
                cout << "FastestFinger" << endl;
            else
                cout << "Ashishgup" << endl;
            continue;
        }
    }
}