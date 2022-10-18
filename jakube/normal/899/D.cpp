#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n < 5) {
        cout << n * (n - 1) / 2;
        return 0;
    }

    auto max = n * 2 - 1;
    long long nine_number = 0;
    while ((nine_number + 1) * 10 - 1 <= max) {
        nine_number = (nine_number + 1) * 10 - 1;
    }

    long long cnt = 0;
    for (int leading_digit = 0; leading_digit < 9; leading_digit++) {
        auto target = (nine_number + 1) * leading_digit + nine_number;
        // (target / 2, target / 2 + 1)
        // ...
        // (1, target - 1)
        if (n >= target - 1)
            cnt += target / 2;
        else if (n >= target / 2 + 1)
            cnt += n - target / 2;
    }
    cout << cnt << endl;
}