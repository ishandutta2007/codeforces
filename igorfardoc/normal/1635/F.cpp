#include<bits/stdc++.h>
#define maxn 300000
#define inf 4000000000000000000ll
#define left left1
#define right right1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int n, q;
ll t[maxn * 4 + 7];

void update(int now, int l, int r, int pos, ll val) {
    if(l == r) {
        t[now] = min(t[now], val);
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= pos) {
        update(now * 2, l, mid, pos, val);
    } else {
        update(now * 2 + 1, mid + 1, r, pos, val);
    }
    t[now] = min(t[now * 2], t[now * 2 + 1]);
}

ll get(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) return inf;
    if(l1 <= l && r <= r1) return t[now];
    int mid = (l + r) / 2;
    return min(get(now * 2, l, mid, l1, r1), get(now * 2 + 1, mid + 1, r, l1, r1));
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
    for(int i = 0; i < maxn * 4 + 7; i++) {
        t[i] = inf;
    }
    cin >> n >> q;
    vector<pair<int, int>> pt(n);
    for(int i = 0; i < n; i++) {
        cin >> pt[i].first >> pt[i].second;
    }
    vi left(n, -1), right(n, -1);
    vi st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && pt[st.back()].second > pt[i].second) {
            st.pop_back();
        }
        if(!st.empty()) {
            left[i] = st.back();
        }
        st.push_back(i);
    }
    st.clear();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && pt[st.back()].second > pt[i].second) {
            st.pop_back();
        }
        if(!st.empty()) {
            right[i] = st.back();
        }
        st.push_back(i);
    }
    vector<array<ll, 3>> e;
    for(int i = 0; i < n; i++) {
        if(left[i] != -1) {
            int id = left[i];
            e.push_back({id, i, (ll)(pt[i].first - pt[id].first) * (pt[i].second + pt[id].second)});
        }
        if(right[i] != -1) {
            int id = right[i];
            e.push_back({i, id, (ll)(pt[id].first - pt[i].first) * (pt[i].second + pt[id].second)});
        }
    }
    sort(e.begin(), e.end());
    vector<array<int, 3>> zap(q);
    vector<ll> ans(q);
    for(int i = 0; i < q; i++) {
        cin >> zap[i][0] >> zap[i][1];
        --zap[i][0];
        --zap[i][1];
        zap[i][2] = i;
    }
    sort(zap.begin(), zap.end());
    int now = e.size() - 1;
    for(int i = q - 1; i >= 0; i--) {
        while(now >= 0 && e[now][0] >= zap[i][0]) {
            update(1, 0, n - 1, e[now][1], e[now][2]);
            --now;
        }
        ans[zap[i][2]] = get(1, 0, n - 1, zap[i][0], zap[i][1]);
    }
    for(const auto& el : ans) {
        cout << el << '\n';
    }
}