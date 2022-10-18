#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // bitset<100011> bs;
    // bs.set();
    vector<bool> bs(100100, true);
    for (int i = 2; i * i < bs.size(); i++) {
        if (bs[i]) {
            for (int j = i * i; j < bs.size(); j += i) {
                bs[j] = 0;
            }
        }
    }

    int n;
    cin >> n;
    
    cout << (n <= 2 ? 1 : 2) << endl;
    for (int i = 0; i < n; i++) {
        cout << (bs[i + 2] ? 1 : 2) << ' ';
    }
    cout << endl;
}