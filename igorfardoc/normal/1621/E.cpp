#include<bits/stdc++.h>
#define maxn 100004
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int t[maxn * 4 + 7];
int lp[maxn * 4 + 7];

vi op;
void clear_tree() {
    for(const auto& el : op) {
        t[el] = 0;
        lp[el] = 0;
    }
    op.clear();
}

void update(int now, int l, int r, int l1, int r1, int val) {
    if(l > r1 || l1 > r) {
        return;
    }
    op.push_back(now);
    if(l1 <= l && r <= r1) {
        t[now] += val;
        lp[now] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(now * 2, l, mid, l1, r1, val);
    update(now * 2 + 1, mid + 1, r, l1, r1, val);
    t[now] = min(t[now * 2], t[now * 2 + 1]) + lp[now];
}


int get_low(ll sum, int k) {
    if(sum % k == 0) {
        return sum / k;
    }
    return (sum - 1) / k + 1;
}

vi a;
vvi b;
int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t1;
    cin >> t1;
    while(t1--) {
        cin >> n >> m;
        a.resize(n);
        clear_tree();
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            update(1, 0, maxn - 1, 0, a[i], 1);
        }
        b.resize(m);
        vvi ans(m);
        for(int i = 0; i < m; i++) {
            int k;
            cin >> k;
            b[i].resize(k);
            ans[i].assign(k, 0);
            for(int j = 0; j < k; j++) {
                cin >> b[i][j];
            }
        }
        vi here(m);
        for(int i = 0; i < m; i++) {
            ll sum = 0;
            for(const auto& el : b[i]) {
                sum += el;
            }
            int need = get_low(sum, b[i].size());
            here[i] = need;
            update(1, 0, maxn - 1, 0, need, -1);
        }
        for(int i = 0; i < m; i++) {
            update(1, 0, maxn - 1, 0, here[i], 1);
            if(t[1] < 0) {
                update(1, 0, maxn - 1, 0, here[i], -1);
                continue;
            }
            ll sum = 0;
            for(const auto& el : b[i]) {
                sum += el;
            }
            for(int j = 0; j < b[i].size(); j++) {
                ll here1 = sum - b[i][j];
                int need1 = get_low(here1, b[i].size() - 1);
                //cout << need1 << ' ' << sum << endl;
                update(1, 0, maxn - 1, 0, need1, -1);
                if(t[1] >= 0) {
                    ans[i][j] = 1;
                }
                update(1, 0, maxn - 1, 0, need1, 1);
            }
            update(1, 0, maxn - 1, 0, here[i], -1);
        }
        for(const auto& el : ans) {
            for(const auto& el1 : el) {
                cout << el1;
            }
        }
        cout << '\n';


    }
}