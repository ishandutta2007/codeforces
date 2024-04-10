#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        int sum = 0, cnt = 0;
        for(int i = 1; sum < x; i += 2){
            sum += i, ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}