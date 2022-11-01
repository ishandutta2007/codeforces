#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, c, d, k, m;
    int mn = 1000000000;
    cin >> c >> d >>n >> m >> k;
    for (int a = 0; a < 10010; ++a) {
        for (int b = 0; b < 10010; ++b) {
            int tasks = a*c + b*d;
            int q = a * n + b;
            if (    q + k >= n*m) {
                mn = min(mn, tasks);

            }
        }
    }

    cout << mn << endl;
}