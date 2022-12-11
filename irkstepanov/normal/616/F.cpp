#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;

struct node
{
    int link, len;
    map<char, int> to;
    ll cnt;
    node()
    {
        link = -1;
        len = 0;
        cnt = 0;
    }
};

vector<node> t;
int last;

void add(char c)
{
    if (t[last].to.count(c) && t[t[last].to[c]].len == t[last].len + 1) {
        last = t[last].to[c];
        return;
    }
    int curr = sz(t);
    t.pb(node());
    t[curr].len = t[last].len + 1;
    int p = last;
    while (true) {
        if (p == -1 || t[p].to.count(c)) {
            break;
        }
        t[p].to[c] = curr;
        p = t[p].link;
    }
    if (p == -1) {
        t[curr].link = 0;
        last = curr;
        return;
    }
    int q = t[p].to[c];
    if (t[q].len == t[p].len + 1) {
        t[curr].link = q;
        last = curr;
        return;
    }
    int clone = sz(t);
    t.pb(node());
    t[clone].len = t[p].len + 1;
    t[clone].to = t[q].to;
    t[clone].link = t[q].link;
    while (true) {
        if (p != -1 && t[p].to.count(c) && t[p].to[c] == q) {
            t[p].to[c] = clone;
        } else {
            break;
        }
        p = t[p].link;
    }
    t[curr].link = clone;
    t[q].link = clone;
    last = curr;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    t.pb(node());

    int n;
    cin >> n;
    vector<string> s(n);
    vector<ll> cost(n);
    int maxlen = 0;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        maxlen = max(maxlen, sz(s[i]));
    }
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    for (int i = 0; i < n; ++i) {
        last = 0;
        for (int j = 0; j < sz(s[i]); ++j) {
            add(s[i][j]);
            t[last].cnt += cost[i];
        }
    }

    vector<vector<int> > v(maxlen + 1);
    for (int i = 0; i < sz(t); ++i) {
        v[t[i].len].pb(i);
    }
    for (int i = maxlen; i >= 0; --i) {
        for (int x : v[i]) {
            if (t[x].link != -1) {
                t[t[x].link].cnt += t[x].cnt;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < sz(t); ++i) {
        ans = max(ans, t[i].cnt * ll(t[i].len));
    }
    cout << ans << "\n";

}