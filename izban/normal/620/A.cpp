#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int x, y, x2, y2;
    cin >> x >> y;
    cin >> x2 >> y2;
    cout << max(abs(x2-x), abs(y2-y)) << endl;
    return 0;
}