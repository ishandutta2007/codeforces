#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

const int MAX_N = 1000010;
const int MOD = 1000000007;

int main(){
    int n;
    while(cin >> n) {
        const int N = 20;
        int A[1 << N] = {};

        REP(i, n) {
            int t;
            cin >> t;
            A[t] ++;
        }

        REP(i, N)REP(S, 1 << N){
            if(0 == (S & (1 << i))){
                A[S] += A[S | (1 << i)];
            }
        }

        int pow2[MAX_N] = {};
        pow2[0] = 1;
        REP(i, MAX_N - 1){
            pow2[i + 1] = (pow2[i] << 1) % MOD;
        }

        int ans = 0;

        REP(s, 1 << N) if(s > 0) {
            int a = A[s];
            if(__builtin_popcount(s) & 1) {
                ans += pow2[a];
                while(ans >= MOD) ans -= MOD;
            } else {
                ans -= pow2[a];
                while(ans < 0) ans += MOD;
            }
        }

        ans = (pow2[n] - ans + MOD) % MOD;

        cout << ans << endl;
    }
    return 0;
}