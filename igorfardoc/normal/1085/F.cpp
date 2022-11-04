#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi f[3];
set<pair<int, int>> pos[3];
vi a;
int n;

void update(vi& t, int r, int val) {
    for(; r < n; r = r | (r + 1)) t[r] += val;
}

int get(vi& t, int r) {
    int ans = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1) ans += t[r];
    return ans;
}

int get(vi& t, int l, int r) {
    return get(t, r) - get(t, l - 1);
}

int getans() {
    int ampref, amsuff, pref, suff;
    for(int i = 0; i < 3; i++) {
        if(!pos[i].empty() && pos[i].begin()->first == 0) {
            pref = i;
            ampref = pos[i].begin()->second + 1;
        }
        if(!pos[i].empty() && pos[i].rbegin()->second == n - 1) {
            suff = i;
            amsuff = n - pos[i].rbegin()->first;
        }
    }
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        int need = (i + 1) % 3;
        int other = (i + 2) % 3;
        if(pos[need].empty() && pos[other].empty()) {
            return n;
        }
        if(pref == i) {
            if(!pos[need].empty()) ans += ampref;
        }
        if(suff == i) {
            if(!pos[need].empty()) ans += amsuff;
        }
        if(pos[need].empty()) continue;
        int fir = pos[need].begin()->first;
        int sec = pos[need].rbegin()->second;
        ans += get(f[i], fir, sec);
    }
    return ans;
}

void delete1(set<pair<int, int>>& s, int val) {
    auto it = s.lower_bound({val + 1, -1});
    --it;
    auto p = *it;
    s.erase(it);
    if(val != p.first) {
        s.insert({p.first, val - 1});
    }
    if(val != p.second) {
        s.insert({val + 1, p.second});
    }
}

void insert1(set<pair<int, int>>& s, int val) {
    int l = val;
    int r = val;
    auto it = s.lower_bound({val, -1});
    if(it != s.begin() && (--it)->second == val - 1) {
        l = it->first;
        s.erase(it);
    }
    it = s.lower_bound({val + 2, -1});
    if(it != s.begin() && (--it)->first == val + 1) {
        r = it->second;
        s.erase(it);
    }
    s.insert({l, r});
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
    int q;
    cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < 3; i++) f[i].resize(n);
    string s;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            a[i] = 0;
        } else if(s[i] == 'S') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
        update(f[a[i]], i, 1);
    }
    int prev = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[prev]) {
            pos[a[prev]].insert({prev, i - 1});
            prev = i;
        }
    }
    pos[a[prev]].insert({prev, n - 1});
    cout << getans() << '\n';
    for(int i = 0; i < q; i++) {
        int id;
        char c;
        cin >> id >> c;
        --id;
        int val;
        if(c == 'R') {
            val = 0;
        } else if(c == 'S') {
            val = 1;
        } else {
            val = 2;
        }
        delete1(pos[a[id]], id);
        update(f[a[id]], id, -1);
        a[id] = val;
        insert1(pos[a[id]], id);
        update(f[a[id]], id, 1);
        cout << getans() << '\n';
    }
}