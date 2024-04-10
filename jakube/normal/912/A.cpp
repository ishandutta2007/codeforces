#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    cin >> A >> B;
    long long x, y, z;
    cin >> x >> y >> z;
    auto needed_A = 2 * x + y;
    auto needed_B = y + 3 * z;
    cout << max(0LL, needed_A - A) + max(0LL, needed_B - B) << '\n';
}