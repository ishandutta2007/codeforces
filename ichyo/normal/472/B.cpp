#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i += m) {
        ans += a[i] - 1;
        ans += a[i] - 1;
    }
    cout << ans << endl;
    return 0;
}