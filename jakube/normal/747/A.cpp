#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    int best = 1;
    for (int a = 1; a*a <= n; a++) {
        if (n % a == 0)
            best = a;
    }

    cout << best << " " << n / best << endl;

    return 0;
}