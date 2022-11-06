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
    int n, p;
    cin >> n >> p;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vi ans;
    for(int x = 1; x < 2000; x++) {
        int now = 0;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            while(now < n && a[now] <= x + i) {
                ++now;
            }
            if((now - i) % p == 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << '\n';
    for(auto& el : ans) {
        cout << el << ' ';
    }
}