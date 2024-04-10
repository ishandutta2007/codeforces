#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pll;

const int amax = 200500;
const int inf = 1e9;

bool bit(int mask, int pos)
{
    return (mask >> pos) & 1;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    int a;
    scanf("%d", &a);

    vector<int> cnt(amax, inf);
    queue<int> q;
    q.push(a);
    cnt[a] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (cnt[x / 2] == inf) {
            cnt[x / 2] = cnt[x] + 1;
            q.push(x / 2);
        }
        if (x * 2 < amax && cnt[x * 2] == inf) {
            cnt[x * 2] = cnt[x] + 1;
            q.push(x * 2);
        }
    }

    vector<char> used(amax, false);
    vector<char> inter(amax, false);
    vector<char> mark(amax, false);
    vector<int> s;
    for (int i = 0; i < amax; ++i) {
        if (cnt[i] != inf) {
            inter[i] = true;
            s.pb(i);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &a);
        q.push(a);
        q.push(0);
        used[a] = true;
        vector<int> vct = {a};
        vector<int> corr;
        if (inter[a]) {
            corr.pb(a);
            mark[a] = true;
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int op = q.front();
            q.pop();
            //cout << x << " " << op << "\n";
            if (inter[x / 2] && !used[x / 2]) {
                cnt[x / 2] += op + 1;
                corr.pb(x / 2);
                mark[x / 2] = true;
            }
            if (!used[x / 2]) {
                used[x / 2] = true;
                vct.pb(x / 2);
                q.push(x / 2);
                q.push(op + 1);
            }
            if (x * 2 < amax && inter[x * 2] && !used[x * 2]) {
                cnt[x * 2] += op + 1;
                corr.pb(x * 2);
                mark[x * 2] = true;
            }
            if (x * 2 < amax && !used[x * 2]) {
                used[x * 2] = true;
                vct.pb(x * 2);
                q.push(x * 2);
                q.push(op + 1);
            }
        }
        for (int x : s) {
            if (!mark[x]) {
                inter[x] = false;
            }
        }
        for (int x : corr) {
            mark[x] = false;
        }
        for (int x : vct) {
            used[x] = false;
        }
        s.swap(corr);
    }
    //cout << "AGA\n";

    int ans = inf;
    for (auto i : s) {
        ans = min(ans, cnt[i]);
    }
    cout << ans << "\n";

}