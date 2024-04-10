#include <iostream>
#include <algorithm>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long res = 1;
    long long pow3 = 1;

    while (pow3 <= n) {
        if (n % pow3 != 0) {
            res = max(res, (n / pow3) + 1);
        }
        pow3 *= 3ll;
    }

    cout << res << "\n";

    return 0;
}