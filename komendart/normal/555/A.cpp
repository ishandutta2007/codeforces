#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int result = n;
    for (int i = 0; i < k; i++) {
        int m; cin >> m;
        bool flag = true;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if (!flag || a != j + 1) {
                flag = false;
                if (j != 0) result++;
            } else {
                result--;
            }
        }
    }

    cout << result << endl;
}