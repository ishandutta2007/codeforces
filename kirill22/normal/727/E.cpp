#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

int A = 26;
vector<vector<int>> trie;
vector<int> term;
vector<int> suf;

void build() {
    trie.pb(vector<int> (A));
    term.pb(-1);
    suf.pb(0);
}

void add(string& t, int i) {
    int v = 0;
    for (auto c : t) {
        int x = c - 'a';
        if (trie[v][x] == 0) {
            trie[v][x] = trie.size();
            trie.pb(vector<int> (A));
            suf.pb(0);
            term.pb(-1);
        }
        v = trie[v][x];
    }
    term[v] = i;
}

void bfs() {
    queue<int> st;
    st.push(0);
    while (st.size() > 0) {
        int v = st.front();
        st.pop();
        for (int i = 0; i < A; i++) {
            if (trie[v][i] == 0) {
                trie[v][i] = trie[suf[v]][i];
            }
            else {
                if (v) suf[trie[v][i]] = trie[suf[v]][i];
                st.push(trie[v][i]);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int m;
    cin >> m;
    build();
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        add(t, i);
    }
    bfs();
    vector<int> dp(n * k, -1);
    int v = 0;
    for (int i = 0; i < k - 1; i++) v = trie[v][s[i] - 'a'];
    for (int i = k - 1; i < n * k + k - 1; i++) {
        v = trie[v][s[i % (n * k)] - 'a'];
        if (term[v] != -1) dp[i % (n * k)] = term[v];
    }
    for (int i = 0; i < k; i++) {
        vector<int> ans;
        set<int> tmp;
        for (int j = i; j < n * k; j += k) if (dp[j] != -1) ans.pb(dp[j]), tmp.insert(dp[j]);
        if (tmp.size() == n) {
            cout << "YES" << endl;
            for (auto x : ans) cout << x + 1 << " ";
            return 0;
        }
    }
    cout << "NO";
}