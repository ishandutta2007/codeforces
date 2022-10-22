#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int res = 0, g = 0, mng = 0, mxg = 0;
    for(int i=0; i<n; i++){
        if(a[i] == b[i]) continue;
        if(a[i] == '1') g++;
        else g--;
        mxg = max(mxg, g);
        mng = min(mng, g);
        res = max(res, abs(g - mxg));
        res = max(res, abs(g - mng));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a != b) cout << -1;
    else cout << res;
    return 0;
}