#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 2000 + 1;
LL a[maxn], b[maxn];
pair<LL, LL> p[maxn];
struct event{
    LL time, rm, add;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i += 1)
        cin >> a[i] >> b[i];
    for(int i = 0; i < m; i += 1) cin >> p[i].first >> p[i].second;
    sort(p, p + m);
    vector<pair<int, int>> vp;
    for(int i = 0; i < m; i += 1){
        while(not vp.empty() and vp.back().second <= p[i].second) vp.pop_back();
        vp.push_back(p[i]);
    }
    multiset<LL> ms;
    vector<event> events;
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < vp.size(); j += 1){
            if(a[i] > vp[j].first) continue;
            if(a[i] <= vp[j].first){
                if(not j or a[i] > vp[j - 1].first) ms.insert(vp[j].second - b[i] + 1);
                events.push_back({
                    vp[j].first - a[i] + 1,
                    vp[j].second - b[i] + 1,
                    j + 1 == vp.size() ? 0 : vp[j + 1].second - b[i] + 1
                });
            }
        }
    }
    LL ans = ms.empty() ? 0 : max(0LL, *prev(ms.end())); 
    sort(events.begin(), events.end(), [](const event& x, const event& y){
        return x.time < y.time;
    });
    for(auto e : events){
        ms.erase(ms.find(e.rm));
        ms.insert(e.add);
        ans = min(e.time + max(0LL, *prev(ms.end())), ans);
    }
    cout << ans;
    return 0;
}