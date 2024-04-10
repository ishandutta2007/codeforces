#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    long long result = n;

    int twos = 0;
    while (n % 2 == 0) {
        twos++;
        n /= 2;
    }

    int fives = 0;
    while (n % 5 == 0) {
        fives++;
        n /= 5;
    }

    while (twos < k) {
        result *= 2;
        twos++;
    }
    while (fives < k) {
        result *= 5;
        fives++;
    }

    cout << result << endl;
}