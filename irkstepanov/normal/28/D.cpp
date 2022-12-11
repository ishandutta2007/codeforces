#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct data
{
    int v, c, l, r, id;
};

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    scanf("%d", &n);

    vector<data> a(n);
    map<int, vector<data> > m;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a[i].v, &a[i].c, &a[i].l, &a[i].r);
        a[i].id = i;
        m[a[i].c + a[i].l + a[i].r].pb(a[i]);
    }

    int ans = 0;
    vector<int> v_ans;

    for (auto it : m) {
        map<int, int> dp;
        map<int, int> lst;
        vector<data>& v = it.second;
        int k = sz(it.second);
        vector<int> pr(k);
        for (int i = 0; i < k; ++i) {
            if (v[i].l) {
                int relax = -1;
                if (dp.count(v[i].r + v[i].c)) {
                    relax = dp[v[i].r + v[i].c] + v[i].v;
                }
                if (relax != -1) {
                    if (!dp.count(v[i].r) || dp[v[i].r] < relax) {
                        dp[v[i].r] = relax;
                        lst[v[i].r] = i;
                        pr[i] = lst[v[i].r + v[i].c];
                    }
                }
            } else {
                if (!dp.count(v[i].r) || dp[v[i].r] < v[i].v) {
                    dp[v[i].r] = v[i].v;
                    lst[v[i].r] = i;
                    pr[i] = -1;
                }
            }
        }
        if (dp.count(0)) {
            if (ans < dp[0]) {
                ans = dp[0];
                int curr = lst[0];
                v_ans = {};
                while (curr != -1) {
                    v_ans.pb(v[curr].id);
                    curr = pr[curr];
                }
                reverse(all(v_ans));
            }
        }
    }

    printf("%d\n", sz(v_ans));
    for (int x : v_ans) {
        printf("%d ", x + 1);
    }
    printf("\n");

}