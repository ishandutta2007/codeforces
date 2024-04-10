#include <iostream>
using namespace std;

long long koren(long long x) {
    long long l=1, r=1'000'000;
    while (l <= r) {
        long long m = (l+r) / 2;
        if (m*m > x) {
            r = m-1;
        } else if (m*m < x) {
            l = m+1;
        } else {
            return m;
        }
    }
    return -1;
}

bool c[1000005];

void sito() {
    for (long long i=2; i*i<1000005; i++) {
        if (c[i] == 0) {
            for (long long j=i*i; j<1000005; j+=i) {
                c[j] = 1;
            }
        }
    }
}

int main() {
    sito();
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        auto y = koren(x);
        if (y == -1 || y == 1) {
            cout << "NO\n";
            continue;
        }
        cout << (c[y] ? "NO\n" : "YES\n");
    }
}