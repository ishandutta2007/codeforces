#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    lint L, R;
    cin >> L >> R;
    puts("YES");
    for (lint i = L; i < R; i += 2) printf("%lld %lld\n", i, i + 1);
}