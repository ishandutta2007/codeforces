#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;

struct node
{
    vector<int> rows;
    int cnt;
    node()
    {
        rows.resize(n);
        cnt = 0;
    }
};

vector<vector<char> > rows;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int q;
    scanf("%d%d%d", &n, &m, &q);

    vector<char> empt(m, false);
    vector<node> v;
    v.pb(node());

    rows.pb(empt);

    for (int i = 1; i <= q; ++i) {
        int type;
        scanf("%d", &type);
        node curr = v.back();
        if (type == 1) {
            int i, j;
            scanf("%d%d", &i, &j);
            --i, --j;
            vector<char> t = rows[curr.rows[i]];
            if (!t[j]) {
                curr.rows[i] = sz(rows);
                t[j] = true;
                rows.pb(t);
                ++curr.cnt;
            }
            v.pb(curr);
        } else if (type == 2) {
            int i, j;
            scanf("%d%d", &i, &j);
            --i, --j;
            vector<char> t = rows[curr.rows[i]];
            if (t[j]) {
                curr.rows[i] = sz(rows);
                t[j] = false;
                rows.pb(t);
                --curr.cnt;
            }
            v.pb(curr);
        } else if (type == 3) {
            int i;
            scanf("%d", &i);
            --i;
            vector<char> t = rows[curr.rows[i]];
            for (int j = 0; j < m; ++j) {
                t[j] ^= 1;
                if (t[j]) {
                    ++curr.cnt;
                } else {
                    --curr.cnt;
                }
            }
            curr.rows[i] = sz(rows);
            rows.pb(t);
            v.pb(curr);
        } else if (type == 4) {
            int i;
            scanf("%d", &i);
            curr = v[i];
            v.pb(curr);
        }
        printf("%d\n", curr.cnt);
    }

}