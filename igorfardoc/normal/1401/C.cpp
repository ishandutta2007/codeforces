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
        auto b = a;
        sort(b.begin(), b.end());
        int min1 = b[0];
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) {
                continue;
            }
            if(a[i] % min1 != 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}