#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi x, y, a1, b1, m1;
int ans;

int score(const pair<pair<int, int>, pair<int, int>>& a) {
    return a.first.first + a.first.second - a.second.first;
}

bool cmp(const pair<pair<int, int>, pair<int, int>>& a, const pair<pair<int, int>, pair<int, int>>& b) {
    return score(a) < score(b);
}
bool comp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    if(a.first.first < b.first.first) {
        return true;
    }
    if(a.first.first > b.first.first) {
        return false;
    }
    return a.first.second > b.first.second;
}

void solve(vector<pair<pair<int, int>, pair<int, int>>>& a) {
    if(a.empty()) {
        return;
    }
    //cout << a.size() << endl;
    int n = a.size();
    vector<pair<pair<int, int>, int>> b;
    multiset<pair<int, int>> rs;
    for(int i = 0; i < n; i++) {
        int l = max(0, a[i].first.first - a[i].second.first);
        int max1 = min(a[i].first.second, a[i].second.first);
        int r = a[i].first.first - (a[i].second.first - max1);
        b.push_back({{l, r}, a[i].second.second});
    }
    sort(b.begin(), b.end(), comp);
    set<int> deleted;
    vector<pair<int, int>> from;
    for(int i = 0; i < n; i++) {
        while(!rs.empty() && b[i].first.second <= (*(rs.rbegin())).first) {
            deleted.insert((*(rs.rbegin())).second);
            from.push_back({(*(rs.rbegin())).second, i});
            rs.erase(--rs.end());
        }
        rs.insert({b[i].first.second, i});
    }
    int now = -10000000;
    for(int i = 0; i < n; i++) {
        if(deleted.find(i) != deleted.end()) continue;
        if(now < b[i].first.first) {
            ++ans;
            now = b[i].first.second;
        }
        int id1 = b[i].second;
        x[id1] = a1[id1] - now;
        y[id1] = m1[id1] - x[id1];
    }
    for(int i = (int)from.size() - 1; i >= 0; i--) {
        int idto = b[from[i].first].second;
        int idfrom = b[from[i].second].second;
        int ahere = a1[idfrom] - x[idfrom];
        x[idto] = a1[idto] - ahere;
        y[idto] = m1[idto] - x[idto];
    }
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
        x.resize(n);
        y.resize(n);
        ans = 0;
        a1.resize(n);
        b1.resize(n);
        m1.resize(n);
        vector<pair<pair<int, int>, pair<int, int>>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first.first >> a[i].first.second >> a[i].second.first;
            a1[i] = a[i].first.first;
            b1[i] = a[i].first.second;
            m1[i] = a[i].second.first;
            a[i].second.second = i;
        }
        sort(a.begin(), a.end(), cmp);
        vector<pair<pair<int, int>, pair<int, int>>> b;
        for(int i = 0; i < n; i++) {
            if(i == 0 || score(a[i - 1]) == score(a[i])) {
                b.push_back(a[i]);
            } else {
                solve(b);
                b.clear();
                b.push_back(a[i]);
            }
        }
        solve(b);
        cout << ans << '\n';
        for(int i = 0; i < n; i++) {
            cout << x[i] << ' ' << y[i] << '\n';
        }
    }
}