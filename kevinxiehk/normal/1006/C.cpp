#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
void solve() {
    int n;
    cin >> n;
    int arr[n + 5];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int pt1 = 0, pt2 = n - 1;
    int ls = 0, rs = 0;
    while(pt1 <= pt2) {
        //cout << pt1 << ' ' << pt2 << '\n';
        if(ls == rs) {
            ans = max(ans, ls);
            ls += arr[pt1];
            rs += arr[pt2];
            pt1++; pt2--;
        }
        else if(ls < rs) {
            ls += arr[pt1];
            pt1++;
        }
        else{
            rs += arr[pt2];
            pt2--;
        }
    }
    if(ls == rs && pt2 - pt1 >= -1) {
        ans = max(ans, ls);
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    
    t = 1;
    //cin >> t;
    
    while(t--) solve();
    return 0;
}