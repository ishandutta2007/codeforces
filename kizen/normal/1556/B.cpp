#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        vector<int> odd;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if(a[i] % 2){
                odd.push_back(i);
            }
        }
        int ans = (int)1e18;
        if(n % 2 == 0 && (int)odd.size() * 2 == n){
            int sum = 0;
            for(int i = 0; i < (int)odd.size(); ++i){
                sum += abs(odd[i] - i * 2);
            }
            mi(ans, sum);
            sum = 0;
            for(int i = 0; i < (int)odd.size(); ++i){
                sum += abs(odd[i] - (i * 2 + 1));
            }
            mi(ans, sum);
        }
        else if(n % 2 == 1 && (int)odd.size() == n / 2){
            int sum = 0;
            for(int i = 0; i < (int)odd.size(); ++i){
                sum += abs(odd[i] - (i * 2 + 1));
            }
            mi(ans, sum);
        }
        else if(n % 2 == 1 && (int)odd.size() == n / 2 + 1){
            int sum = 0;
            for(int i = 0; i < (int)odd.size(); ++i){
                sum += abs(odd[i] - i * 2);
            }
            mi(ans, sum);
        }
        if(ans == (int)1e18) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}