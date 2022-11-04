#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int _gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return _gcd(b, a % b);
}

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
        string s;
        cin >> s;
        vi am(26, 0);
        for(int i = 0; i < n; i++) {
            ++am[s[i] - 'a'];
        }
        sort(am.begin(), am.end());
        int ans = 1;
        for(int i = 2; i <= n; i++) {
            int am1 = _gcd(i, k);
            int sz = i / am1;
            int can = 0;
            for(int j = 0; j < am.size(); j++) {
                can += am[j] / sz;
            }
            if(can >= am1) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }
}