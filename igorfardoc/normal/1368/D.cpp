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
    int n;
    cin >> n;
    vi am(20, 0);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for(int j = 0; j < 20; j++) {
            if((a >> j) & 1) {
                ++am[j];
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int now = 0;
        for(int j = 0; j < 20; j++) {
            if(am[j] != 0) {
                --am[j];
                now ^= (1 << j);
            }
        }
        ans += (ll)now * now;
    }
    cout << ans;
}