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
        int n, k;
        cin >> n >> k;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vi b(k);
        for(int i = 0; i < k; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int now = n - k - 1;
        ll res = 0;
        for(int i = n - 1; i >= n - k; i--) {
            res += a[i];
            if(b[n - i - 1] == 1) {
                res += a[i];
            }
        }
        for(int i = 0; i < k; i++) {
            if(b[i] == 1) {
                continue;
            }
            res += a[now - b[i] + 2];
            now -= b[i] - 1;
        }
        cout << res << '\n';
    }
}