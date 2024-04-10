#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    lint N;
    cin >> N;
    map<lint, int> m;
    for (lint i = 2; i <= 1000000; i++)
    {
        while (N % i == 0) N /= i, m[i]++;
    }
    if (N > 1) m[N]++;
    if (m.size() == 0) puts("1");
    else if (m.size() == 1) cout << m.begin()->first << endl;
    else puts("1");
}