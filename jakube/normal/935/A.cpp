#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if ((n - i) % i == 0)
            cnt++;
    }
    cout << cnt << endl;
}