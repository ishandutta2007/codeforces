#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int T;

inline int get1 (string s) {
    int cur1 = 0, cur2 = 0;
    int rem1 = 5, rem2 = 5;

    for (int i = 0; i < 10; i++) {
        if (s[i] == '?') s[i] = (i & 1? '0' : '1');

        if (i & 1) {
            if (s[i] == '1') cur2++;
            rem2--;
        }
        else {
            if (s[i] == '1') cur1++;
            rem1--;
        }

        if (cur2 + rem2 < cur1) return i + 1;
    }

    return 10;
}


inline int get2 (string s) {
    int cur1 = 0, cur2 = 0;
    int rem1 = 5, rem2 = 5;

    for (int i = 0; i < 10; i++) {
        if (s[i] == '?') s[i] = (i & 1? '1' : '0');

        if (i & 1) {
            if (s[i] == '1') cur2++;
            rem2--;
        }
        else {
            if (s[i] == '1') cur1++;
            rem1--;
        }

        if (cur1 + rem1 < cur2) return i + 1;
    }

    return 10;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) {
        string s;

        cin >> s;

        cout << min(get1(s), get2(s)) << '\n';
    }
}