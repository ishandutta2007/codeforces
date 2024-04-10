// Hydro submission #634aa7880168d01a5b22c8fa@1665836937604
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    int cnt = 0;
    while (n) {
        int digit = n % 10;
        if (digit == 4 || digit == 7) {
            cnt++;
        }
        n /= 10;
    }

	cout << ((cnt == 4 || cnt == 7) ? "YES" : "NO");

    return 0;
}