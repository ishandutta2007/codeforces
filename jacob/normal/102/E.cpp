#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    for (int i = 0; i < 4; i++) {
        long long dx = x2 - x1;
        long long dy = y2 - y1;
        long long u = dx * x3 + dy * y3;
        long long v = dx * y3 - dy * x3;
        long long w = x3*x3 + y3*y3;
        if (dx == 0 && dy == 0) {
            cout << "YES" << endl;
            return 0;
        }
        if (w != 0 && u % w == 0 && v % w == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
        x1 = -x1;
        swap(x1, y1);
    }
    cout << "NO" << endl;
    return 0;
}