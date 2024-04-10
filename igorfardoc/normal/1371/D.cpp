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
        vvi a(n, vi(n, 0));
        int k;
        cin >> k;
        for(int i = 0; i < n; i++) {
            if(k > 0) {
                --k;
                a[i][i] = 1;
            }
        }
        for(int i = 0; i < n - 1; i++) {
            for(int j = 1 + i; j < n; j++) {
                if(k > 0) {
                    --k;
                    a[j - i - 1][j] = 1;
                }
            }
            for(int i1 = n - i - 1; i1 < n; i1++) {
                if(k > 0) {
                    --k;
                    a[i1][i1 - (n - i - 1)] = 1;
                }
            }
        }
        int rmax = -1;
        int rmin = 1000;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += a[i][j];
            }
            rmax = max(rmax, sum);
            rmin = min(rmin, sum);
        }
        int cmax = -1;
        int cmin = 1000;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += a[j][i];
            }
            cmax = max(cmax, sum);
            cmin = min(cmin, sum);
        }
        cout << cmax - cmin + rmax - rmin << '\n';
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}