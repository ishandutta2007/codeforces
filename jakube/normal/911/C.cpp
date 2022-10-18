#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> k(3);
    for (int i = 0; i < 3; i++) {
        cin >> k[i];
    }
    sort(k.begin(), k.end());
    
    if (k[0] == 1
        || (k[0] == 2 && k[1] == 2)
        || (k[0] == 2 && k[1] == 4 && k[2] == 4)
        || (k[0] == 3 && k[1] == 3 && k[2] == 3)) {
        cout << "YES" << '\n';
        return 0;
    }

    cout << "NO" << '\n';
}