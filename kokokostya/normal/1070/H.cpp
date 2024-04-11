#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
#include <cassert>
#include <numeric>

//#define FAST_ALLOCATOR_MEMORY 2e8
//#include "optimization.h"

using namespace std;

typedef long long ll;
typedef long double ld;

typedef unsigned long long ull;

const ull P = 239;

set< ull > get(const string &s) {
    set< ull > q;
    int n = (int)s.size();
    for(int l = 0;l < n;l++) {
        ull h = 0;
        for(int r = l;r < n;r++) {
            h = h * P + s[r];
            q.insert(h);
        }
    }
    return q;
}

char buffer[20];

inline void read_string(string &s) {
    scanf("%s", &buffer);
    s = buffer;
}

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\input.txt", "r", stdin);
    freopen("C:\\Users\\aytel\\CLionProjects\\common\\output.txt", "w", stdout);
#endif

    int n;

    scanf("%d", &n);

    unordered_map< ull, int > cnt, any;

    vector< string > ss(n);

    for(int i = 0;i < n;i++) {
        string s;
        read_string(s);
        ss[i] = s;
        set< ull > q = get(s);
        for(ull x : q) {
            cnt[x]++;
            any[x] = i;
        }
    }

    int T;

    scanf("%d", &T);

    for(int it = 0;it < T;it++) {
        string s;
        read_string(s);
        ull h = 0;
        for(char c : s) h = h * P + c;
        int tmp = cnt[h];
        printf("%d %s\n", tmp, tmp ? ss[ any[h] ].c_str() : "-");
    }

    return 0;
}