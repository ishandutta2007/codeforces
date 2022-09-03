#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

int get()
{
    string S;
    cin >> S;
    if (S == "mistake") exit(0);
    if (S == "end") exit(0);
    if (S == "e") exit(0);
    if (S == "start") return -1;
    return (S == "x" ? 1 : 0);
}

int main()
{
    while (true)
    {
        get();
        lint lo = 1, hi = 2;
        while (true)
        {
            printf("? %lld %lld\n", lo, hi);
            fflush(stdout);
            int ret = get();
            if (ret)
            {
                if (lo != 1) lo++;
                hi++;
                break;
            }
            lo = hi;
            hi = lo * 2;
        }
        if (lo == 1)
        {
            puts("? 2 3");
            fflush(stdout);
            int ret = get();
            if (ret) lo = 1;
            else lo = 2;
        }
        else
        {
            while (hi > lo + 1)
            {
                cerr << lo << "," << hi << endl;
                lint c = (hi + lo) / 2 - 1;
                printf("? %lld %lld\n", c, hi);
                fflush(stdout);
                int ret = get();
                if (!ret) hi = c + 1;
                else lo = c + 1;
            }
        }
        printf("! %lld\n", lo);
        fflush(stdout);
    }
}