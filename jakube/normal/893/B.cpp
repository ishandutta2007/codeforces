#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int best = 1;
    for (int k = 1; k < 13; k++) {
        int x = ((1 << k) - 1) << (k - 1);
        if (n % x == 0)
            best = x;
    }
    cout << best << endl;
}