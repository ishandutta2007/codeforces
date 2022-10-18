#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    cin >> k;
    vector<int> cnts(10, 1);
    long long c = 1;
    string s = "codeforces";
    int idx = 0;
    while (c < k) {
        c /= cnts[idx];
        cnts[idx]++;
        c *= cnts[idx];
        idx = (idx + 1) % 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << string(cnts[i], s[i]);
    }
    cout << '\n';
    
}