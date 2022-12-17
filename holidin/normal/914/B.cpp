#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;

int b[2*N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int i, j, t, n;
    cin >> n;
    int a = -10000000;
    j = 0;
    for (i = 0; i < n; ++i) {
        cin >> j;
        b[j]++;
    }
    vector <int> v;
    for (i = 1; i <= 100000; ++i)
    if (b[i] > 0) {
        v.push_back(b[i]);
    }
    bool found = false;
    for (i = 0; i < v.size(); ++i)
    if (v[i] % 2 == 1)
        found = true;
    if (found)
        cout << "Conan";
    else
        cout << "Agasa";

}