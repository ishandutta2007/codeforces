#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int result = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        result += abs(x);
    }
    cout << result << endl;
}