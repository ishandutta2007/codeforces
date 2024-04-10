#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, n, k, o;
    cin >> n;
    k = 0;
    vector <int> v;
    for (i = max(1, n - 100); i <= n; ++i) {
        j = i;
        o = 0;
        while (j > 0) {
            o += j % 10;
            j /= 10;
        }
        if (o + i == n) {
            ++k;
            v.push_back(i);
        }
    }
    cout << k << endl;
    for (i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}