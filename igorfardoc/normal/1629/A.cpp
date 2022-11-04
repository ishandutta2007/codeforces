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
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            if(a[i].first <= k) {
                k += a[i].second;
            }
        }
        cout << k << '\n';
    }
}