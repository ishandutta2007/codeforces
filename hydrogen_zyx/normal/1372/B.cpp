#include <iostream>
#include <vector>
using namespace std;
vector<bool> prime(10000000);
vector<int> v;
int main() {
    fill(prime.begin(), prime.begin() + 10000000, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < 10000000; i++) {
        if (prime[i]) {
            v.push_back(i);
            for (int j = i + i; j < 10000000; j += i) {
                prime[j] = 0;
            }
        }
    }
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool f = 1;
        int chu = 0;
        for (int i = 0; i < v.size(); i++) {
            if (n % v[i] == 0) {
                f = 0;
                chu = v[i];
                break;
            }
        }
        if (f) {
            cout << 1 << ' ' << n - 1 << endl;
            continue;
        }
        cout << n / chu << ' ' << n - n / chu << endl;
    }
}