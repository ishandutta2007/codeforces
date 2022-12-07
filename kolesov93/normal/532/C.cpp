#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 <= x2 && y1 <= y2) {
        puts("Polycarp");
        return 0;
    }
    if (x1 + y1 <= max(x2,y2)) {
        puts("Polycarp");
        return 0;
    }
    puts("Vasiliy");


    return 0;
}