#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

int get(int l, int r){
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    int x; cin >> x;
    return x;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("con", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int al = get(1, n);
        int low = 1, high = n, mid;
        while(low < high){
            mid = low + high >> 1;
            if(get(1, mid) == al){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        int rp = low;
        int rc = get(1, low - 1);
        rc = al - rc + 1;
        low = 1, high = n, mid;
        while(low < high){
            mid = low + high >> 1;
            if(mid * (mid - 1) / 2 + rc * (rc - 1) / 2 >= al){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        cout << "! " << rp - rc - low + 1 << ' ' << rp - rc + 1 << ' ' << rp << '\n';
        cout.flush();
    }
    return 0;
}