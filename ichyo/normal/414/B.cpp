#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
const int MOD = 1000000007;
int solve(int n, int k){
    vector<int> curr(n + 1, 0);
    REP(i, n) curr[i + 1] = 1;
    REP(_, k - 1){
        vector<int> next(n + 1, 0);
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j += i){
                next[j] += curr[i];
                while(next[j] >= MOD){
                    next[j] -= MOD;
                }
            }
        }
        curr.swap(next);
    }
    int ans = 0;
    REP(i, n){
        ans += curr[i + 1];
        while(ans >= MOD) ans -= MOD;
    }
    return ans;
}
int main(){
    int n, k;
    while(cin >> n >> k){
        cout << solve(n, k) << endl;
    }
    return 0;
}