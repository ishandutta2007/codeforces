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
        vector<array<int, 3>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        map<int, int> costl;
        map<int, int> costr;
        map<pair<int, int>, int> cost;
        int l = 1000000000;
        int r = -1;
        for(int i = 0; i < n; i++) {
            l = min(l, a[i][0]);
            r = max(r, a[i][1]);
            auto it = costl.find(a[i][0]);
            if(it == costl.end() || it->second > a[i][2]) {
                costl[a[i][0]] = a[i][2];
            }
            it = costr.find(a[i][1]);
            if(it == costr.end() || it->second > a[i][2]) {
                costr[a[i][1]] = a[i][2];
            }
            auto it1 = cost.find({a[i][0], a[i][1]});
            if(it1 == cost.end() || it1->second > a[i][2]) {
                cost[{a[i][0], a[i][1]}] = a[i][2];
            }
            int ans = 2000000000;
            it1 = cost.find({l, r});
            if(it1 != cost.end()) {
                ans = min(ans, it1->second);
            }
            ans = min(ans, costl[l] + costr[r]);
            cout << ans << '\n';
        }
    }
}