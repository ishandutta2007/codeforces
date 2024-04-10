#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int zeroEnd = 0;
    int oneEnd = n - 1;
    while (zeroEnd < n && s[zeroEnd] == '0') {
        zeroEnd++;
    }
    while (oneEnd >= 0 && s[oneEnd] == '1') {
        oneEnd--;
    }
    for (int i = 0; i < zeroEnd; i++) {
        cout << '0';
    }
    if (oneEnd != zeroEnd - 1) {
        cout << '0';
    }
    for (int i = oneEnd + 1; i < n; i++) {
        cout << '1';
    }
    cout << "\n";
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}