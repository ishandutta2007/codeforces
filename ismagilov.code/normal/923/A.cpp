#include <bits/stdc++.h>

using namespace std;

bool u[1000001];
long long p[1000001], pp[1000001];

int main()
{
    long long x;
    cin >> x;

    for (long long i = 2; i <= 1000000; ++i){
        if (!u[i]){
            p[i] = i;
            for (long long j = i * i; j <= 1000000; j += i){
                u[j] = 1;
                p[j] = i;
            }
        }
    }

    for (long long i = 2; i <= 1000000; ++i){
        pp[i] = p[i];
        if (u[i])
            pp[i] = max(pp[i], pp[i / p[i]]);
    }

    long long ans = x;
    long long xx = x;
    while (xx != 1){
        long long pr = p[xx];
        xx /= p[xx];

        for (long long i = x - pr + 1; i <= x; ++i){
            if (u[i])
                ans = min(ans, i - pp[i] + 1);
            else
                ans = min(ans, i);
        }
    }

    cout << ans << '\n';
    return 0;
}