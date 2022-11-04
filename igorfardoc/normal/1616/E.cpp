#include<bits/stdc++.h>
#define inf 1000000000000000000ll
#define maxn 1000001
#define int ll
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int t[maxn * 4 + 7];

vi op;
void clear_tree() {
    for(const auto& el : op) {
        t[el] = 0;
    }
    op.clear();
}

void update(int now, int l, int r, int pos, int val) {
    op.push_back(now);
    if(l == r) {
        t[now] += val;
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= pos) {
        update(now * 2, l, mid, pos, val);
    } else {
        update(now * 2 + 1, mid + 1, r, pos, val);
    }
    t[now] = t[now * 2] + t[now * 2 + 1];
}

ll get_sum(int now, int l, int r, int l1, int r1) {
    if(l > r1 || l1 > r) {
        return 0;
    }
    if(l1 <= l && r <= r1) {
        return t[now];
    }
    int mid = (l + r) / 2;
    return get_sum(now * 2, l, mid, l1, r1) + get_sum(now * 2 + 1, mid + 1, r, l1, r1);
}

ll get_inv(vi& p) {
    clear_tree();
    ll res = 0;
    int n = p.size();
    for(int i = 0; i < n; i++) {
        if(p[i] != n - 1) {
            res += get_sum(1, 0, n - 1, p[i] + 1, n - 1);
        }
        update(1, 0, n - 1, p[i], 1);
    }
    return res;
}

signed main()
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
        string s, t;
        cin >> s >> t;
        vvi poses(26);
        for(int i = 0; i < n; i++) {
            poses[s[i] - 'a'].push_back(i);
        }
        vvi right(n + 1, vi(26, n));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 26; j++) {
                if((int)(s[i] - 'a') < j) {
                    right[i][j] = i;
                    continue;
                }
                right[i][j] = right[i + 1][j];
            }
        }
        ll ans = inf;
        int end = -1;
        int here = right[0][t[0] - 'a'];
        if(here != n) {
            ans = min(ans, (ll)here);
        }
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                break;
            }
            end = i;
            if(i == n - 1) break;
            int here = right[i + 1][t[i + 1] - 'a'];
            if(here == n) continue;
            ans = min(ans, (ll)here - (i + 1));
        }
        vi now(26, 0);
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < poses[i].size(); j++) {
                if(poses[i][j] <= end) {
                    now[i] = j + 1;
                } else {
                    break;
                }
            }
        }
        clear_tree();
        ll anshere = 0;
        for(int i = end + 1; i < n - 1; i++) {
            int here = t[i] - 'a';
            if(now[here] == poses[here].size()) break;
            int pos1 = poses[here][now[here]++];
            int amafter = 0;
            if(pos1 != n - 1) {
                amafter = get_sum(1, 0, n - 1, pos1 + 1, n - 1);
            }
            int ambefore = (i - (end + 1)) - amafter;
            anshere += amafter;
            anshere += pos1 - i;//(end + 1 + ambefore);
            ll minadding = inf;
            update(1, 0, n - 1, pos1, 1);
            for(int j = 0; j < (int)(t[i + 1] - 'a'); j++) {
                if(now[j] == poses[j].size()) continue;
                int poshere = poses[j][now[j]];
                int amafter = 0;
                if(poshere != n - 1) {
                    amafter = get_sum(1, 0, n - 1, poshere + 1, n - 1);
                }
                ll ansh = amafter + poshere - (i + 1);
                minadding = min(minadding, ansh);
            }
            //cout << i << ' ' << anshere << ' ' << anshere + max(0ll, min1 - (i + 1)) << endl;
            ans = min(ans, anshere + minadding);
            
        }
        if(ans == inf) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans << '\n';
    }
}