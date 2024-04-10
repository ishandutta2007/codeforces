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
        int l = 1;
        int r = 1000000001;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            vector<ll> b(n);
            for(int i = 0; i < n; i++) {
                b[i] = a[i];
            }

            bool ok = true;
            for(int i = n - 1; i >= 2; i--) {
                if(b[i] < mid) {
                    ok = false;
                    break;
                }
                ll d = min((ll)a[i] / 3, (b[i] - mid) / 3);
                b[i - 1] += d;
                b[i - 2] += d * 2;
            }
            if(b[0] < mid || b[1] < mid) {
                ok = false;
            }
            if(ok) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << '\n';
    }


}