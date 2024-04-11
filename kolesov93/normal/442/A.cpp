#include <iostream>
#include <map>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool a[5][5];

int main() {
    map<char, int> q;
    q['R'] = 0;
    q['G'] = 1;
    q['B'] = 2;
    q['Y'] = 3;
    q['W'] = 4;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c = getchar();
        while (c < 'A' || c > 'Z') c = getchar();

        a[q[c]][getchar() - '1'] = true;
    }

    int ans = 1e9;
    for (int m1 = 0; m1 < 32; ++m1)
        for (int m2 = 0; m2 < 32; ++m2) {
            int res = 0;
            for (int i = 0; i < 5; ++i) {
                if (m1 & (1 << i)) ++res;
                if (m2 & (1 << i)) ++res;
            }
            if (res >= ans) continue;

            bool failure = false;
            for (int x = 0; x < 5; ++x)
                for (int y = 0; y < 5; ++y)
                    if (a[x][y]) {
                        for (int ax = 0; ax < 5; ++ax)
                            for (int ay = 0; ay < 5; ++ay)
                                if (x != ax || y != ay)
                                    if (a[ax][ay]) {
                                        bool cool = false;
                                        if (x != ax && ((m1 & (1 << x)) || (m1 & (1 << ax)))) cool = true;
                                        if (y != ay && ((m2 & (1 << y)) || (m2 & (1 << ay)))) cool = true;
                                        if (!cool) failure = true;
                                    }
                    }
            if (!failure) ans = res;
        }
    cout << ans << endl;


    return 0;
}