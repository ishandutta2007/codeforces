#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    uint64_t a, b, c;
    cin >> a >> b >> c;
    uint64_t out = 2*c;
    if (a != b) {
        out++;
    }
    uint64_t db = min(a, b);
    out += 2*db;
    a -= db;
    b -= db;
    cout << out << endl;
}