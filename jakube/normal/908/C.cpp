#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(9);

    int n, r;
    cin >> n >> r;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<double> last(1001, -r);
    for (auto x : v) {
        double y = r;
        if (x - 2 * r >= 0)
            y = max(y, last[x - 2 * r]);
        if (x + 2 * r <= 1000)
            y = max(y, last[x + 2 * r]);

        for (int X = max(1, x - 2*r + 1); X <= min(1000, x + 2*r - 1); X++) {
            if (X == x) {
                y = max(y, last[x] + 2 * r);
            } else {
                y = max(y, last[X] + sqrt(4 * r * r - abs(x - X) * abs(x - X)));
            }
        }
        cout << y << " ";
        last[x] = y;
    }
    cout << endl;
}