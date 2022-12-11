#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{

    map<string, int> host, req;
    vector<string> name;
    int q;
    int n = 0, k = 0;
    vector<vector<int> > g;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;
        string a = "", b = "";
        int i;
        for (i = 7; i < sz(s) && s[i] != '/'; ++i) {
            a += s[i];
        }
        for (; i < sz(s); ++i) {
            b += s[i];
        }
        if (!host.count(a)) {
            host[a] = n++;
            name.pb(a);
            g.pb({});
        }
        if (!req.count(b)) {
            req[b] = k++;
        }
        g[host[a]].pb(req[b]);
    }

    map<int, vector<int> > m;

    for (int i = 0; i < n; ++i) {
        sort(all(g[i]));
        g[i].resize(unique(all(g[i])) - g[i].begin());
        m[sz(g[i])].pb(i);
    }

    vector<vector<int> > ans;

    for (auto& it : m) {
        map<vector<int>, vector<int> > magic;
        for (int x : it.second) {
            magic[g[x]].pb(x);
        }
        for (auto& tmp : magic) {
            if (sz(tmp.second) > 1) {
                ans.pb(tmp.second);
            }
        }
    }

    cout << sz(ans) << "\n";
    for (vector<int>& v : ans) {
        for (int t : v) {
            cout << "http://" << name[t] << " ";
        }
        cout << "\n";
    }

}