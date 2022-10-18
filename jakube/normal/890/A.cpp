#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(6);
    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    do {
        if (v[0]+v[1]+v[2] == v[3]+v[4]+v[5]) {
            cout << "YES" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << "NO" << endl;
}