#include <iostream>

using namespace std;

int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

int main() {
    int n;
    cin >> n;

    int ansD = 1, ansN = 0;

    for (int denom = 1; denom <= n; denom++) {
        int numer = n - denom;
        if (denom <= numer || gcd(numer, denom) != 1) continue;
        if (ansN * denom < ansD * numer) {
            ansN = numer;
            ansD = denom;
        }
    }

    cout << ansN << ' ' << ansD << endl;
    return 0;
}