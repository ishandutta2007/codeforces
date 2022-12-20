#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

vector<int> children[3000];

int szes[3000];
int c[3000];

int out[3000];

vector<int> nums;
bool ok = true;

int dfs(int strt) {
    if (szes[strt] != -1) return szes[strt];
    szes[strt] = 0;
    for (int nxt : children[strt]) {
        szes[strt] += 1 + dfs(nxt);
    }
    return szes[strt];
}

void dfs2(int strt) {
    if (dfs(strt) < c[strt]) {
        //cout << dfs(strt) << ' ' << c[strt] << endl;
        ok = false;
        return;
    }

    if (nums.size() <= c[strt]) {
        ok = false;
        return;
    }

    out[strt] = nums[c[strt]];
    nums.erase(begin(nums)+c[strt]);
    for (int nxt : children[strt]) {
        dfs2(nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int p[n+1];
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
        children[p[i]].pb(i);
        szes[i] = -1;
    }

    for (int i = 1; i <= n; i++) nums.pb(i);

    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) dfs2(i);
    }


    if (!ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << out[i] << ' ';
        }
        cout << endl;
    }
}