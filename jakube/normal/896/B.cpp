#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c;
    cin >> n >> m >> c;

    int l = 0;
    int r = n - 1;
    vector<int> v(n, -1);
    while (m-- > 0) {
        int p;
        cin >> p;
        if (p * 2 <= c) {
            bool b = false;
            for (int i = 0; i < l; i++) {
                if (p < v[i]) {
                    b = true;
                    cout << i + 1 << endl;
                    v[i] = p;
                    break;
                }
            }
            if (!b) {
                cout << l + 1 << endl;
                v[l] = p;
                l++;
            }
        } else {
            bool b = false;
            for (int i = n - 1; i > r; i--) {
                if (p > v[i]) {
                    b = true;
                    cout << i + 1 << endl;
                    v[i] = p;
                    break;
                }
            }
            if (!b) {
                cout << r + 1 << endl;
                v[r] = p;
                r--;
            }
        }
        if (l > r)
            break;
    }
}