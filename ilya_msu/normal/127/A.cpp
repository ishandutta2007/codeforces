#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>

using std::sqrt;

using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;





int main() {
    int n, k;
    cin >> n >> k;
    double s = 0, x, y, x0, y0;
    cin >> x0 >> y0;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        s += sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
        x0 = x;
        y0 = y;
    }
    s = s * k / 50;
    printf("%lf\n", s);
    return 0;
}