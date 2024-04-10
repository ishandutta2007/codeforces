#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int main()
{
    lint A, B, C, D;
    cin >> A >> B >> C >> D;
    lint ret = 0;
    lint nall = (C - B + 1) * (D - C + 1);
    for (lint x = A; x <= B; x++)
    {
        if (x > D - B) ret += nall;
        else if (x >= D - C and x >= C - B)
        {
            lint n = D - B - x + 1;
            ret += nall - n * (n + 1) / 2;
        }
        else if (x < D - C and x >= C - B)
        {
            lint h = x - (C - B);
            ret += h * (1 + C - B) + 1LL * (C - B) * (C - B + 1) / 2;
        }
        else if (x >= D - C and x < C - B)
        {
            ret += nall - (C - B - x + 1) * (D - C + 1) - (D - C) * (D - C + 1) / 2;
        }
        else
        {
            ret += 1LL * x * (x + 1) / 2;
        }
    }
    cout << ret << '\n';
}