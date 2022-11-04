#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi f1, f2;
int now;

void update(vi& f, int r, int val) {
    for(; r < now; r = r | (r + 1)) {
        f[r] += val;
    }
}

int get(vi& f, int r) {
    int res = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1) {
        res += f[r];
    }
    return res;
}

int get(vi& f, int l, int r) {
    if(l > r) return 0;
    return get(f, r) - get(f, l - 1);
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
    int n, m;
    cin >> n >> m;
    vector<array<int, 4>> e; // row, 0/1, +1/-1, id
    vi p(n), s(n), b(n), inc(m), pref(m);
    vi ans(m, 0);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < m; i++) cin >> inc[i];
    for(int i = 0; i < m; i++) cin >> pref[i];
    set<int> all;
    now = 0;
    for(int i = 0; i < n; i++) {
        all.insert(p[i] + b[i]);
        all.insert(p[i] - b[i]);
        e.push_back({p[i], 0, 1, p[i] + b[i]});
        e.push_back({p[i], 1, -1, p[i] - b[i]});
        e.push_back({s[i], 1000000, -1, p[i] + b[i]});
        e.push_back({s[i], 1000001, 1, p[i] - b[i]});
    }
    for(int i = 0; i < m; i++) {
        all.insert(inc[i] + pref[i]);
        all.insert(inc[i] - pref[i]);
        all.insert(inc[i] + pref[i] + 1);
        all.insert(inc[i] - pref[i] + 1);
        e.push_back({inc[i], i + 10, inc[i] - pref[i], inc[i] + pref[i]});
    }
    map<int, int> d;
    for(const auto& el : all) {
        d[el] = now++;
    }
    for(int i = 0; i < e.size(); i++) {
        e[i][3] = d[e[i][3]];
        if(e[i][1] % 1000000 != 0 && e[i][1] % 1000000 != 1) {
            e[i][2] = d[e[i][2]];
        }
    }
    f1.resize(now);
    f2.resize(now);
    sort(e.begin(), e.end());
    for(const auto& el : e) {
        if(el[1] % 1000000 != 0 && el[1] % 1000000 != 1) {
            int id = el[1] - 10;
            ans[id] += get(f1, 0, now - 1);
            //cout << ans[id] << endl;
            ans[id] -= get(f1, el[3] + 1, now - 1);
            ans[id] += get(f2, el[2] + 1, now - 1);
        } else {
            if(el[1] % 1000000 == 0) {
                update(f1, el[3], el[2]);
            } else {
                update(f2, el[3], el[2]);
            }
        }
    }
    for(const auto& el : ans) {
        cout << el << ' ';
    }
}