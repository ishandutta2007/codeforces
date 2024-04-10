#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int cost = 0;
        for (int i = 0; i < n; i++) {
            bool prevWhite = false;
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '.') {
                    if (prevWhite) {
                        if (y <= 2 * x) cost += y;
                        else            cost += 2 * x;
                        prevWhite = false;
                    } else {
                        prevWhite = true;
                    }
                } else {
                    if (prevWhite) {
                        cost += x;
                        prevWhite = false;
                    }
                }
            }
            if (prevWhite) cost += x;
        }
        cout << cost << "\n";
    }
}