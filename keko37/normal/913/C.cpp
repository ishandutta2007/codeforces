#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<unordered_map>

typedef long long llint;

using namespace std;

const int MAXN = 35;
const llint INF = 4000000000000000000LL;

int n, l;
llint c[MAXN];
unordered_map <int, llint> dp;

llint f (int mask) {
    if (mask==0) return 0;
    if (dp[mask]!=0) return dp[mask];
    llint res=INF;
    for (int i=30; i>=0; i--) {
        if (mask & (1<<i)) {
            for (int j=0; j<=min(n-1, i); j++) {
                res=min(res, f(mask ^ (1<<i))+(1<<i)/(1<<j)*c[j]);
            }
            for (int j=min(n, i+1); j<n; j++) {
                res=min(res, c[j]);
            }
            break;
        }
    }
    dp[mask]=res;
    return res;
}

int main () {
    cin >> n >> l;
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }
    cout << f(l);
    return 0;
}