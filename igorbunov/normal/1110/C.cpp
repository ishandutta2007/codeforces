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

int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}
signed main() {
    vector<int> d(26);
    int d1[26] = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401} ;
    d[1] = 0;
    int q;
    cin >> q;
    for (int ij = 0; ij < q; ij++) {
        int a;
        cin >> a;
        int now = 2;
        int ind = 1;
        while (now <= a) {
            now *= 2;
            ind++;
        }
        if (a == now - 1) {
            cout << d1[ind] << endl;
        } else {
            cout << now - 1 << endl;
        }
    }
}