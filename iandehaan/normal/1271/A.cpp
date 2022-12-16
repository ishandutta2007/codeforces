#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int out = 0;
    if (e > f) {
        int num = min(a, d);
        a -= num;
        d -= num;
        out += e*num;

        num = min(b, min(c, d));
        b -= num;
        c -= num;
        d -= num;
        out += f*num;
    } else {
        int num = min(b, min(c, d));
        b -= num;
        c -= num;
        d -= num;
        out += f*num;

        num = min(a, d);
        a -= num;
        d -= num;
        out += e*num;
    }
    cout << out << endl;
}