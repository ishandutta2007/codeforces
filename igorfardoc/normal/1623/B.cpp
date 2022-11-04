#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<array<int, 3>> ans;

void solve(vector<pair<int, int>>& a) {
    if(a.empty()) {
        return;
    }
    if(a.size() == 1) {
        ans.push_back({a[0].first, a[0].second, a[0].first});
        return;
    }

    int id1 = 0;
    for(int i = 1; i < a.size(); i++) {
        if(a[id1].second - a[id1].first < a[i].second - a[i].first) {
            id1 = i;
        }
    }
    vector<pair<int, int>> fir, sec;
    int id2 = -1;
    for(int i = 0; i < a.size(); i++) {
        if(i == id1) continue;
        if(id2 == -1 || a[id2].second - a[id2].first < a[i].second - a[i].first) {
            id2 = i;
        }
    }
    int l1 = a[id1].first;
    int r2 = a[id1].second;
    int r1, l2;
    int here;
    //cout << a[id2].first << ' ' << a[id2].second << endl;
    if(a[id2].second == r2) {
        l2 = a[id2].first;
        r1 = l2 - 2;
        here = l2 - 1;
    } else {
        r1 = a[id2].second;
        l2 = r1 + 2;
        here = r1 + 1;
    }
    ans.push_back({a[id1].first, a[id1].second, here});
    for(int i = 0; i < a.size(); i++) {
        if(i == id1) continue;
        if(a[i].second <= r1) {
            fir.push_back(a[i]);
        } else {
            sec.push_back(a[i]);
        }
    }
    //cout << a.size() << ' ' << fir.size() << endl;
    solve(fir);
    solve(sec);
}



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
        vector<pair<int, int>> a(n);
        ans.clear();
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        solve(a);
        for(const auto& el : ans) {
            cout << el[0] << ' ' << el[1] << ' ' << el[2] << '\n';
        }
        cout << '\n';
    }
}