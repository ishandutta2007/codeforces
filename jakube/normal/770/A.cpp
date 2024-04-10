#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string s;
    for (int i = 0; i < n; i++) {
        s += (char)('a' + (i % k));
    }
    cout << s << endl;
}