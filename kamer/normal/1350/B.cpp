#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> s(n+1);
        for (int i = 1; i <= n; i++) cin >> s[i];
        vector<int> m(n+1, 1);
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 2 * i; j <= n; j += i) {
                if (s[i] < s[j]) m[i] = max(m[i], 1 + m[j]);
            }
        }
        int M = 0;
        for (int i = 1; i <= n; i++) {
            M = max(M, m[i]);
        }
        cout << M << "\n";
    }
    return 0;
}