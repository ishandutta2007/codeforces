#include <iostream>
#include <vector>
using namespace std;

const int customBound = 450;
long long primes[customBound];
int numPrimes;

void eratosthenes() {
    vector<bool> isPrime(customBound, true);
    int index = 0;
    for (int i = 2; i < customBound; i++) {
        if (isPrime[i]) {
            primes[index] = i;
            index++;
            for (int j = 2 * i; j < customBound; j += i) {
                isPrime[j] = false;
            }
        }
    }
    numPrimes = index;
}

int main(void) {
    eratosthenes();
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long result = 1;
    for (int i = 0; i < numPrimes; i++) {
        int m1=1000, m2=1000;
        for (int j = 0; j < n; j++) {
            int expo = 0;
            while ((a[j] % primes[i]) == 0) {
                expo++;
                a[j] /= primes[i];
            }
            if (expo <= m1) {
                m2 = m1;
                m1 = expo;
            } else if (expo < m2) {
                m2 = expo;
            }
        }
        for (int e = 0; e < m2; e++) result *= primes[i];
    }
    if (n == 2) {
        if (a[0] == a[1]) {
            cout << result * a[0] << "\n";
        } else {
            cout << result * a[0] * a[1] << "\n";
        }
    } else {
        int A;
        if (a[0] != a[1]) {
            A = a[2];
        } else {
            A = a[0];
        }
        int countBad = 0;
        for (int i = 0; i < n; i++) {
            if (A != a[i]) countBad++;
        }
        if (countBad <= 1) cout << result * A << "\n";
        else cout << result << "\n";
    }
    return 0;
}