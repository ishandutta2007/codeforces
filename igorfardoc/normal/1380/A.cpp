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
            --a[i];
        }
        int l = 0;
        int r = n - 1;
        bool ok = false;
        while(r - l > 1) {
            int max1 = r - l;
            if(a[l] == max1) {
                ++l;
            } else if(a[r] == max1) {
                --r;
            } else {
                ok = true;
                cout << "YES\n";
                for(int i = l + 1; i < r; i++) {
                    if(a[i] == max1) {
                        cout << i << ' ' << i + 1 << ' ' << i + 2 << '\n';
                    }
                }
                break;
            }
        }
        if(!ok) {
            cout << "NO\n";
        }
    }
}