#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> ans;

int main() {
    v.resize(3);
    for(int i = 0; i < 3; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int ma = max(v[0].second, max(v[1].second, v[2].second));
    int mi = min(v[0].second, min(v[1].second, v[2].second));
    for(int i = mi; i <= ma; i++) ans.push_back({v[1].first, i});
    for(int i = v[0].first; i < v[1].first; i++) ans.push_back({i, v[0].second});
    for(int i = v[1].first+1; i <= v[2].first; i++) ans.push_back({i, v[2].second});
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
}