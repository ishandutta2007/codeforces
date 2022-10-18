#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        
        vector<int> v(n + 1, 0);
        bool fine = false;

        for (int j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            if (tmp < 0) v[-tmp] |= 2;
            else v[tmp] |= 1;

            if (v[abs(tmp)] == 3) fine = true;
        }

        if (!fine) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}