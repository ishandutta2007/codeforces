#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct data
{
    string type;
    int val;
};

int main()
{

    //ifstream cin("input");
    //ofstream cout("output");

    //freopen("input", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, int> m;
    vector<data> ans;

    while (n--) {
        string s;
        cin >> s;
        if (s == "insert") {
            int val;
            cin >> val;
            ++m[val];
            ans.pb({"insert", val});
        } else if (s == "getMin") {
            int val;
            cin >> val;
            if (m.empty()) {
                ans.pb({"insert", val});
                ans.pb({"getMin", val});
                ++m[val];
            } else {
                while (!m.empty() && m.begin()->first < val) {
                    ans.pb({"removeMin", 0});
                    --m.begin()->second;
                    if (m.begin()->second == 0) {
                        m.erase(m.begin());
                    }
                }
                if (m.empty() || m.begin()->first != val) {
                    ans.pb({"insert", val});
                    ++m[val];
                }
                ans.pb({"getMin", val});
            }
        } else {
            if (m.empty()) {
                ans.pb({"insert", 0});
                ++m[0];
            }
            --m.begin()->second;
            if (m.begin()->second == 0) {
                m.erase(m.begin());
            }
            ans.pb({"removeMin", 0});
        }
    }

    cout << sz(ans) << "\n";
    for (auto& d : ans) {
        cout << d.type;
        if (d.type != "removeMin") {
            cout << " " << d.val;
        }
        cout << "\n";
    }

}