#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first < b.first) {
        return true;
    }
    if(a.first > b.first) {
        return false;
    }
    return a.second > b.second;
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
    int n, p;
    cin >> n >> p;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[0] == a[n - 1]) {
        cout << "0";
        return 0;
    }
    vector<vector<pair<int, int>>> ost(p);
    vector<set<pair<int, int>>> ost1(p);
    int xmax = a[n - 1] - 1;
    int r1 = xmax;
    int l1 = 0;
    while(r1 - l1 > 1) {
        int mid = (l1 + r1) / 2;
        int now = 0;
        bool ok = false;
        for(int i = 0; i < n; i++) {
            while(now < n && a[now] <= i + mid) {
                ++now;
            }
            if(now - i <= 0) {
                ok = true;
                l1 = mid;
                break;
            }
        }
        if(!ok) {
            r1 = mid;
        }
    }
    int xmin = r1;
    int now = 0;
    for(int sum = xmin; sum < n + xmax; sum++) {
        while(now < n && a[now] <= sum) {
            ++now;
        }
        int iost = now % p;
        int xost = (sum % p - iost + p) % p;
        int maxi = n - 1;
        if(maxi % p > iost) {
            maxi -= maxi % p - iost;
        } else {
            maxi -= maxi % p;
            --maxi;
            if(maxi > 0) {
                maxi -= maxi % p - iost;
            }
        }
        int mini = iost;
        if(maxi >= mini) {
            ost[xost].push_back({sum - maxi, sum - mini});
        }
    }
    for(int i = 0; i < p; i++) {
        sort(ost[i].begin(), ost[i].end(), cmp);
        if(ost[i].empty()) {
            continue;
        }
        int l = ost[i][0].first;
        int r = ost[i][0].second;
        for(int j = 1; j < ost[i].size(); j++) {
            if(ost[i][j].first > r) {
                ost1[i].insert({l, r});
                l = ost[i][j].first;
                r = ost[i][j].second;
            } else {
                r = max(r, ost[i][j].second);
            }
        }
        ost1[i].insert({l, r});
    }

    vi ans;
    for(int x = xmin; x <= xmax; x++) {
        auto it = ost1[x % p].upper_bound({x + 1, -100});
        if(it == ost1[x % p].begin() || ((*(--it)).second < x)) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << '\n';
    for(auto& el : ans) {
        cout << el << ' ';
    }
}