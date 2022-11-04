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
        vi am(n + 1);
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            while(a > 0) {
                if(a <= n) {
                    ++am[a];
                }
                a /= 2;
            }
        }
        bool ok = true;
        for(int i = n; i >= 1; i--) {
            if(am[i] == 0) {
                ok = false;
                break;
            }
            int now = i;
            while(now > 0) {
                --am[now];
                now /= 2;
            }
        }
        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}