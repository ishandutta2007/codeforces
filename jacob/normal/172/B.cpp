#include <iostream>
using namespace std;

long long a, b, m;

inline long long next(long long p) {
    return (a * p + b) % m;
}

int main(void) {
    long long r;
    cin >> a >> b >> m >> r;
    for (int i = 0; i < 300000; i++) {
        r = next(r);
    }
    int res = 0;
    long long rn = r;
    do {
        rn = next(rn);
        ++res;
    } while (rn != r);
    cout << res << endl;
    return 0;
}