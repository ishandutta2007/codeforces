#include <iostream>
#include <vector>
using namespace std;

const int BOUND = 3301;
vector<int> primes;
vector<bool> isPrime(BOUND + 5, true);

void eratosthenes() {
    for (int i = 2; i < BOUND; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < BOUND; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main(void) {
    eratosthenes();
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bool found = false;
        for (auto p : primes) {
            if (a[i] % p == 0) {
                found = true;
                l[i] = 1;
                while (a[i] % p == 0) {
                    l[i] *= p;
                    a[i] /= p;
                }
                if (a[i] == 1) {
                    l[i] = -1;
                    r[i] = -1;
                } else {
                    r[i] = a[i];
                }
                break;
            }
        }
        if (!found) {
            l[i] = -1;
            r[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) cout << l[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << r[i] << " ";
}