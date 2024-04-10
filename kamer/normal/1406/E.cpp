#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
using namespace std;
const int BOUND = 100000;
const int SMALL_BOUND = 316;
vector<int> isPrime(BOUND + 1, true);
vector<int> smallPrimes;
vector<int> largePrimes;

void eratosthenes(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            if (i < SMALL_BOUND) {
                smallPrimes.push_back(i);
            } else {
                largePrimes.push_back(i);
            }
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

bool findAnomaly(vector<bool> &rem, int m, int n, int res) {
    int count = 0;
    for (int x = m; x <= n; x += m) {
        if (!rem[x]) count++;
    }
    if (count != res) {
        return true;
    } else {
        return false;
    }
}

int giveAnomaly(vector<bool> &rem, int m, int n, int res) {
    int count = 0;
    for (int x = m; x <= n; x += m) {
        if (!rem[x]) count++;
    }
    return count;
}

void fillRem(vector<bool> &rem, int m, int n) {
    for (int x = m; x <= n; x += m) rem[x] = true;
}

int main(void) {
    int n;
    cin >> n;
    eratosthenes(n);
    int result = 1;
    vector<bool> rem(n + 1, false);
    for (int i = 0; i < largePrimes.size(); i++) {
        cout << "B " << largePrimes[i] << "\n";
        cout.flush();
        int res; cin >> res;
        fillRem(rem, largePrimes[i], n);
        
        if ((i % 100 == 99) || (i == (largePrimes.size() - 1))) {
            cout << "A 1\n";
            cout.flush();
            int res; cin >> res;
            if (findAnomaly(rem, 1, n, res)) {
                for (int j = (i / 100) * 100; j <= i; j++) {
                    cout << "A " << largePrimes[j] << "\n";
                    cout.flush();
                    cin >> res;
                    if (findAnomaly(rem, largePrimes[j], n, res)) {
                        result = largePrimes[j];
                        goto LABEL;
                    }
                }
            }
        }
    }
    
LABEL:
    for (auto p : smallPrimes) {
        int expo = 0;
        cout << "B " << p << "\n";
        cout.flush();
        int res;
        cin >> res;
        fillRem(rem, p, n);
        int x = p;
        while (x <= n) {
            cout << "A " << x << "\n";
            cout.flush();
            cin >> res;
            if (findAnomaly(rem, x, n, res)) {
                expo++;
            } else {
                break;
            }
            x *= p;
        }
        for (int i = 0; i < expo; i++) {
            result *= p;
        }
    }

    cout << "C " << result << "\n";
    cout.flush();
}