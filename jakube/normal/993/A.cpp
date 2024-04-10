#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> sq1(4);
    for (int i = 0; i < 4; i++) {
        cin >> sq1[i].first >> sq1[i].second;
        sq1[i].first *= 2;
        sq1[i].second *= 2;
    }
    sort(sq1.begin(), sq1.end());
    int x_min_1 = sq1[0].first;
    int x_max_1 = sq1[3].first;
    int y_min_1 = sq1[0].second;
    int y_max_1 = sq1[3].second;

    vector<pair<int, int>> sq2(4);
    for (int i = 0; i < 4; i++) {
        cin >> sq2[i].first >> sq2[i].second;
        sq2[i].first *= 2;
        sq2[i].second *= 2;
    }
    sort(sq2.begin(), sq2.end());
    int d1 = sq2[0].first + sq2[0].second;
    int d2 = -sq2[0].first + sq2[0].second;
    int d3 = sq2[3].first + sq2[3].second;
    int d4 = -sq2[3].first + sq2[3].second;

    for (int x = -200; x <= 200; x++) {
        for (int y = -200; y <= 200; y++) {
            bool first = false;
            if (x_min_1 <= x && x <= x_max_1 && y_min_1 <= y && y <= y_max_1)
                first = true;
            bool second = true;
            if (y < -x + d1)
                second = false;
            if (y > x + d2)
                second = false;
            if (y > -x + d3)
                second = false;
            if (y < x + d4)
                second = false;

            if (first && second) {
                cout << "YES" << '\n';
                // cout << x << " " << y << endl;
                return 0;
            }
        }
    }
    cout << "NO" << '\n';
    
}