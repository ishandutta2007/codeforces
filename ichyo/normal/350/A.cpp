#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<int> a(n), b(m);
        REP(i, n) cin >> a[i];
        REP(i, m) cin >> b[i];
        int ans = max(*min_element(a.begin(), a.end()) * 2, *max_element(a.begin(), a.end()));
        if(*min_element(b.begin(), b.end()) <= ans) ans = -1;
        cout << ans << endl;
    }
    return 0;
}