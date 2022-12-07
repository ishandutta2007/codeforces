#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);
const int N = 5111;
char s[N];
int n, p;
char last;

int main() {
    scanf("%d%d\n", &n, &p);
    scanf("%s", s);

    if (p == 1) {
        puts("NO");
        return 0;
    }

    last = 'a' + p - 1;
    bool found = false;
    for (int i = n - 1; i >= 0; --i) {
        for (char c = s[i] + 1; c <= last; ++c) {
            bool cool = true;
            if (i && c == s[i - 1]) cool = false;
            if (i - 2 >= 0 && c == s[i - 2]) cool = false;
            if (i + 1 < n && p < 3 && n > 2) cool = false;

            if (!cool) continue;

            s[i] = c;
            for (int j = i + 1; j < n; ++j) {
                for (char nc = 'a'; nc <= last; ++nc)
                    if (nc != s[j - 1] && nc != s[j - 2]) {
                        s[j] = nc;
                        break;
                    }
            }

            found = true;
            break;
        }
        if (found == true) break;
    }

    if (!found) {
        puts("NO");
        return 0;
    }
    puts(s);


    return 0;
}