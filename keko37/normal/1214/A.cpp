#include<bits/stdc++.h>

using namespace std;

int n, d, e, sol;

int main () {
    cin >> n >> d >> e;
    sol = n;
    for (int i=0; i*e <= n; i += 5) {
        sol = min(sol, (n - i*e) % d);
    }
    cout << sol;
    return 0;
}