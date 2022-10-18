#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<int> v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, d;
    cin >> m >> d;
    
    int days = v[m-1] - (7 + 1 - d);
    cout << 1 + (days + 6) / 7 << endl;

    return 0;
}