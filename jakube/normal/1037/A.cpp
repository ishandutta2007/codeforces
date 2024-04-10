#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int l = 0;
    while (n) {
        l++;
        n >>= 1;
    }
    cout << l << '\n';
}