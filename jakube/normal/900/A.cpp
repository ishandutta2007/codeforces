#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < 0)
            cnt++;
    }
    if (cnt <= 1 || cnt >= n - 1) 
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}