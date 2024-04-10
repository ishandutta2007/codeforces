#include <bits/stdc++.h>
using namespace std;
const int N = 300;


map <int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int i,j, n;
    cin >> n;
    int p = 0;
    int k = 0;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        if (m[j] == 0)
            ++k;
        else
            m[j]--;
        m[i]++;
    }
    cout << k << endl;
}