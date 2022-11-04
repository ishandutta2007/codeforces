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
        vi a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        int mx = -1;
        int id = -1;
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(a[i] > mx || b[i] > mx) {
                mx = max(a[i], b[i]);
                id = i;
            }
        }
        ans = mx;
        int other = min(a[id], b[id]);
        for(int i = 0; i < n; i++) {
            if(i == id) continue;
            other = max(other, min(a[i], b[i]));
        }
        cout << ans * other << '\n';
    }
}