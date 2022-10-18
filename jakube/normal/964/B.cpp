#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, A, B, C, T;
    cin >> n >> A >> B >> C >> T;
    
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        res += A + max(0, C - B) * (T - t);
    }
    cout << res << endl;
}