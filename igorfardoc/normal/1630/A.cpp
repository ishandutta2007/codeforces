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
        if(k == n - 1 && n == 4) {
            cout << -1 << '\n';
            continue;
        }
        set<pair<int, int>> ans;
        if(k == n - 1) {
            for(int i = 0; i < n; i++) {
                if(i == 0 || i == 1) {
                    ans.insert({0, 1});
                    continue;
                }

                if(i == n - 1 || i == n - 2) {
                    ans.insert({n - 2, n - 1});
                    continue;
                }
                if(i == 2 || i == n - 4) {
                    ans.insert({2, n - 4});
                    continue;
                }
                if(i == 3 || i == n - 3) {
                    ans.insert({3, n - 3});
                    continue;
                }
                int fir = i;
                int sec = (n - 1) ^ fir;
                ans.insert({min(fir, sec), max(fir, sec)});
            }
        } else {
            int other = (n - 1) ^ k;
            for(int i = 0; i < n; i++) {
                if(i == 0) {
                    ans.insert({0, other});
                    continue;
                }
                if(i == other) {
                    ans.insert({0, other});
                    continue;
                }
                if(i == n - 1) {
                    ans.insert({k, n - 1});
                    continue;
                }
                if(i == k) {
                    ans.insert({k, n - 1});
                    continue;
                }
                int fir = i;
                int sec = (n - 1) ^ fir;
                ans.insert({min(fir, sec), max(fir, sec)});
            }
        }
        for(const auto& el : ans) {
            cout << el.first << ' ' << el.second << '\n';
        }
    }
}