#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n+1), indices(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        indices[v[i]] = i;
    }
    
    int last = n+1;
    for (int i = 1; i <= n; i++) {
        while (last > 1 && indices[last - 1] <= i) {
            last--;
            cout << last << ' ';
        }
        cout << '\n';
    }


    return 0;
}