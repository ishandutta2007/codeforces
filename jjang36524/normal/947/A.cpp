#include<bits/stdc++.h>

using namespace std;
using lint = long long int;

const int INF = 1e9;
const lint INFL = 1e18;

int main(void) {
        ios_base::sync_with_stdio(false), cin.tie(NULL);
    int N;  cin >> N;
    int fp = 0;

    int oN = N;
    vector<int> fac;
    for (int p = 2; p*p <= N; p ++) {
        if (N % p == 0) {
            fac.push_back(p);
            while (N % p == 0)
                N /= p;
        }
    }

    if (N != 1)
        fac.push_back(N);

    int t = fac.back();
    N = oN;
    int res = N;

    for (int i = N-t+1; i <= N; i ++) {
        int ti = i;
        int c = -1;
        fac.clear();

        for (int p = 2; p * p <= ti; p ++) {
            if (ti % p == 0) {
                fac.push_back(p);

                while (ti % p == 0) {
                    ti /= p;
                }
            }
        }

        if (ti != 1)
            fac.push_back(ti);

        if (i - (int)fac.back() + 1 >= 3)
            res = min(res, i - (int)fac.back() + 1);
    }

    cout << res << endl;


}