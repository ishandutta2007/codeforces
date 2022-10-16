#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;
 
#define int long long
#define endl '\n'

signed main() {
    int x, y, z;
    cin >> x >> y >> z;
    int a, b, c;
    cin >> a >> b >> c;
    if (a < x) {
        cout << "NO";
        return 0;
    }
    a -= x;
    if (a + b < y) {
        cout << "NO";
        return 0;
    }
    if (a + b + c - y < z) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}