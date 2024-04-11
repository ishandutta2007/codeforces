#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);

int main() {
    string s = "CODEFORCES";
    string w;
    cin >> w;

    if (w.size() <= s.size()) {
        puts("NO");
        return 0;
    }

    for (int i = 0; i < w.size(); ++i)
        for (int j = 1; i + j <= w.size(); ++j)
            if (w.substr(0, i) + w.substr(i + j) == s) {
                puts("YES");
                return 0;
            }

        puts("NO");

    return 0;
}