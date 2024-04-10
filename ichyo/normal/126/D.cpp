#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

typedef unsigned long long LL;

void myassert(bool cond) {
    while(!cond);
}

int main(){
    vector<LL> fib = {1, 2, 3};
    while(fib.back() <= 1000000000000000000LL) {
        LL a = fib[fib.size() - 1];
        LL b = fib[fib.size() - 2];
        fib.push_back(a + b);
    }
    int t;
    cin >> t;
    while(t--) {
        LL n;
        cin >> n;
        int l = upper_bound(fib.begin(), fib.end(), n) - fib.begin() - 1;
        myassert(l >= 0 && l + 1 < fib.size());
        myassert(fib[l] <= n && fib[l + 1] > n);
        vector<int> bits(l + 1, 0);
        {
            LL m = n;
            for(int i = l; i >= 0; i--) {
                myassert(0 <= i && i < bits.size());
                if(m >= fib[i]) {
                    bits[i] = 1;
                    m -= fib[i];
                }
            }
            myassert(m == 0);
        }

        LL dp[100][3][3] = {};
        dp[l + 1][bits[l]][(l - 1 >= 0 ? bits[l - 1] : 0)] = 1;
        for(int i = l; i >= 0; i--) {
            REP(d1, 3) REP(d2, 3){
                LL curr = dp[i + 1][d1][d2];
                if(curr == 0) continue;
                // cd == 0
                REP(cd, 2) if(d1 - cd >= 0) {
                    int nd1 = d2 + d1 - cd;
                    int nd2 = d1 - cd;
                    if(i - 2 >= 0 && bits[i - 2]) nd2++;
                    if(nd1 < 3 && nd2 < 3) {
                        dp[i][nd1][nd2] += curr;
                    }
                }
            }
        }
        LL ans = dp[0][0][0];
        cout << ans << endl;
    }

    return 0;
}