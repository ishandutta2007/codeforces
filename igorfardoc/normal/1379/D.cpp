#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, h, m, k;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> h >> m >> k;
    if(k == 1) {
        cout << "0 0";
        return 0;
    }
    vector<pair<pair<int, int>, int>> ban;
    for(int i = 0; i < n; i++) {
        int hi, mi;
        cin >> hi >> mi;
        int l = (mi + 1) % (m / 2);
        int r = (mi + k - 1) % (m / 2);
        if(l < r) {
            ban.push_back({{l, r}, i});
        } else {
            ban.push_back({{0, r}, i});
            ban.push_back({{l, m / 2 - 1}, i});
        }
        //cout << l << ' ' << r << endl;
    }
    //cout << 1234 << endl;
    vector<pair<int, int>> ev;
    for(int i = 0; i < ban.size(); i++) {
        ev.push_back({ban[i].first.first, 1});
        ev.push_back({ban[i].first.second + 1, -1});
        ev.push_back({ban[i].first.first - 1, 0});
    }
    ev.push_back({m / 2 - 1, 0});
    ev.push_back({0, 0});
    sort(ev.begin(), ev.end());
    int min1 = 1000000;
    int minid = 0;
    int now = 0;
    for(int i = 0; i < ev.size(); i++) {
        //cout << ev[i].first << ' ' << ev[i].second << '\n';
        if(ev[i].first < 0 || ev[i].first >= m / 2) {
            continue;
        }
        if(i != 0 && ev[i].first != 0 && ev[i].first != ev[i - 1].first) {
            if(now < min1) {
                min1 = now;
                minid = ev[i - 1].first;
            }
        }
        now += ev[i].second;
    }
    if(now < min1) {
        min1 = now;
        minid = m / 2 - 1;
    }
    cout << min1 << ' ' << minid << '\n';
    for(int i = 0; i < ban.size(); i++) {
        if(ban[i].first.first <= minid && ban[i].first.second >= minid) {
            cout << ban[i].second + 1 << ' ';
        }
    }
}