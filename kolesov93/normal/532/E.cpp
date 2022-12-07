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

int n;
string a, b;

int main() {
    cin >> n >> a >> b;

    set<string> cands;
    for (size_t i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) {
            cands.insert(a.substr(0,i) + b[i] + a.substr(i));
            cands.insert(b.substr(0,i) + a[i] + b.substr(i));
            break;
        }

    int ans = 0;
    for (auto&& c : cands) {
        int m1 = 0, m2 = 0;
        int pos = 0;
        for (size_t i = 0; i < c.size(); ++i)
            if (a[pos] == c[i]) {
                ++pos;
            } else {
                ++m1;
            }

        pos = 0;
        for (size_t i = 0; i < c.size(); ++i)
            if (b[pos] == c[i]) {
                ++pos;
            } else {
                ++m2;
            }
        if (m1 <= 1 && m2 <= 1) ++ans;
    }

    cout << ans << endl;


    return 0;
}