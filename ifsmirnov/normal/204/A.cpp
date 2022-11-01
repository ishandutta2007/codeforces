#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long i64;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

i64 fd(i64 x) {return x%10;}
i64 ld(i64 x) {i64 t = x%10; while (x) {t = x%10; x /= 10;}; return t;}

i64 get(i64 x)
{
    if (x < 10ll)
        return x;
    i64 y = x-x%10;
    return y/10 - 1 + 9 + (fd(x) >= ld(x));
}

int main()
{
    i64 l, r;
    cin >> l >> r;
    cout << get(r) - get(l-1) << endl;
    return 0;
}