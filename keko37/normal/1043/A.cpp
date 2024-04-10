#include<bits/stdc++.h>

using namespace std;

int n, sum, sol;

int main () {
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sum += 2*x;
        sol = max(sol, x);
    }
    sol = max(sol, sum/n + 1);
    cout << sol;
    return 0;
}