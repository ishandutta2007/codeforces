#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, l;
        cin >> n >> l;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0; i < l; i++) {
            int am0 = 0;
            int am1 = 0;
            for(int j = 0; j < n; j++) {
                if((a[j] >> i) & 1) {
                    ++am1;
                } else {
                    ++am0;
                }
            }
            if(am1 > am0) {
                ans ^= (1 << i);
            }
        }
        cout << ans << '\n';
    }
}