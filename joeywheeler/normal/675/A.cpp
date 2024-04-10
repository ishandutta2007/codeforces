#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

long long a, b, c;

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);
    long long t = b-a;
    // c * (>=0) = t
    bool y;
    if (c == 0) y = t == 0;
    else {
        if (t%c != 0) y = false;
        else y = t/c >= 0;
    }
    printf(y ? "YES\n" : "NO\n");
}