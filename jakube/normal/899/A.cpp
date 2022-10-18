#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ones = 0;
    int twos = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1)
            ones++;
        else
            twos++;
    }

    if (ones > twos) {
        cout << twos + (ones - twos) / 3 << '\n';
    } else {
        cout << ones << '\n';
    }
}