#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> mini(n, n+1);
    vector<int> maxi(n, -1);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        mini[x] = min(mini[x], i);
        maxi[x] = max(maxi[x], i);
    }
    vector<pair<int, int>> pas(n);
    for(int i = 0; i < n; i++) {
        pas[i] = {mini[i], maxi[i]};
    }
    sort(pas.begin(), pas.end());
    pas.push_back({n+1, -1});
    int ans = 0;
    int globalMax = -1, prevMax = -1;
    bool sad = true;
    for(int i = 0; i < n; i++) {
        if(pas[i].first == n+1) continue;
        if(pas[i].first > globalMax) {
            ans += max(0, globalMax - prevMax - 1);
            ans += max(0, pas[i].second - pas[i].first - 1);
            prevMax = pas[i].second;
        }
        else if(pas[i].first > prevMax) {
            ans += max(0, globalMax - prevMax - 1);
            prevMax = globalMax;
        }
        globalMax = max(globalMax, pas[i].second);
    }
    ans += max(0, globalMax - prevMax - 1);
    cout << ans << '\n';
}