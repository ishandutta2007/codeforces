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
        int n;
        cin >> n;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(n <= 2) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 10000;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int anshere = 0;
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    int d1 = j - i;
                    int d2 = k - j;
                    ll here = (a[j] - a[i]) * d2;
                    if(here % d1 != 0) {
                        ++anshere;
                        continue;
                    }
                    ll c = a[j] + here / d1;
                    if(c == a[k]) continue;
                    ++anshere;
                }
                ans = min(ans, anshere);
            }
        }
        cout << ans << '\n';
    }

}