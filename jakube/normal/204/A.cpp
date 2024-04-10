#include <bits/stdc++.h>
using namespace std;

long long pow(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

long long f(long long x) {
    if (x == 0)
        return 0;

    vector<int> digits;
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }

    long long result = 0;
    
    // leading digit
    long long number = 0;
    for (int i = digits.size() - 2; i > 0; i--) {
        number = 10 * number + digits[i];
    }
    result += number + 1;
    if (digits[0] < digits.back()) {
        result--;
    }

    // lower leading digit
    int last_digit = digits.back();
    int cnt = digits.size();
    while (cnt > 0) {
        for (int d = last_digit - 1; d > 0; d--) {
            result += pow(10, cnt-2);
        }
        cnt--;
        last_digit = 10;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long l, r;
    cin >> l >> r;
    
    cout << f(r) - f(l-1) << endl;
    return 0;
}