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
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX_NUM = 200001;
vector<bool> isPrime(MAX_NUM, true);

void eratosthenes() {
    for (int i = 2; i < MAX_NUM; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < MAX_NUM; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

ll ask(int x, int y) {
    cout << "? " << x + 1 << " " << y + 1 << "\n";
    cout.flush();
    ll res;
    cin >> res;
    return res;
}

void respond(vector<ll>& values) {
    cout << "!";
    for (auto val : values) cout << " " << val;
    cout << "\n";
    cout.flush();
}
    
ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

void bruteForce(int n) {
    vector<vector<ll>> results(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            results[i][j] = ask(i, j);
            results[j][i] = results[i][j];
        }
    }

    vector<ll> values(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            values[i] = gcd(values[i], results[i][j]);
        }
    }

    if (n == 3) {
        if ((values[0] % 2 == 0) && (values[1] % 2 == 0) && (values[2] % 2 == 0)) {
            int maxVal = -1, maxIndex = -1;
            for (int i = 0; i < n; i++) {
                if (maxVal < values[i]) {
                    maxVal = values[i], maxIndex = i;
                }
            }

            values[maxIndex] /= 2;
        }
    }

    respond(values);
}

static inline int getRand(int n) {
    return rand() % n;
}

static inline int getDiffRand(int n, int a) {
    int b = a;
    while (b == a) b = rand() % n;
    return b;
}

static inline tuple<int, int> get2Rand(int n) {
    int a = getRand(n);
    int b = getDiffRand(n, a);
    return { a, b };
}

void codeForce(int n) {
    static const int TRIES_MAX = 3500;
    static const int TRIES_GCD = 500;
    static const int TRIES_PRIME = 1000;

    ll currentMax = -1;
    int maxIndex0 = -1, maxIndex1 = -1;
    for (int i = 0; i < TRIES_MAX; i++) {
        auto [a, b] = get2Rand(n);
        auto res = ask(a, b);
        if (currentMax < res) {
            maxIndex0 = a, maxIndex1 = b, currentMax = res;
        }
    }

    ll val0 = currentMax;
    for (int i = 0; i < TRIES_GCD; i++) {
        val0 = gcd(val0, ask(maxIndex0, getDiffRand(n, maxIndex0)));
    }

    ll val1 = currentMax / val0;
    if (val1 > val0) swap(val0, val1), swap(maxIndex0, maxIndex1);

    int primeIndex = -1;
    ll primeVal = -1;
    for (int i = 0; i < TRIES_PRIME; i++) {
        int a = getDiffRand(n, maxIndex0);
        ll res = ask(a, maxIndex0);
        if (isPrime[res / val0] && (res / val0 > val0 * 3 / 4)) {
            primeIndex = a;
            primeVal = res / val0;
        }
    }

    if (primeIndex == -1) exit(3);
    
    vector<ll> values(n);
    for (int i = 0; i < n; i++) {
        if (i == primeIndex) values[primeIndex] = primeVal;
        else {
            values[i] = ask(i, primeIndex) / primeVal;
        }
    }

    respond(values);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    eratosthenes();
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 100) {
            bruteForce(n);
        } else {
            codeForce(n);
        }
    }
}