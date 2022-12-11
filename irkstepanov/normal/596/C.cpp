#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define openStream(in, out) ifstream cin(in); ofstream cout(out);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{

    int n;
    cin >> n;

    vector<pair<int, int> > p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    sort(all(p));
    map<int, vector<int> > m;
    for (int i = 0; i < n; ++i) {
        m[p[i].second - p[i].first].pb(i);
    }

    vector<int> ans(n);
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    map<pii, int> color;

    for (int i = n - 1; i >= 0; --i) {
        if (m.count(w[i])) {
            vector<int>& v = m[w[i]];
            ans[i] = v.back();
            color[p[ans[i]]] = i;
            v.pop_back();
            if (v.empty()) {
                m.erase(w[i]);
            }
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        int c = color[p[i]];
        if (p[i].first) {
            if (color[mp(p[i].first - 1, p[i].second)] > c) {
                cout << "NO\n";
                return 0;
            }
        }
        if (p[i].second) {
            if (color[mp(p[i].first, p[i].second - 1)] > c) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << p[ans[i]].first << " " << p[ans[i]].second << "\n";
    }

}