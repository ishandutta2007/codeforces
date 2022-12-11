#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct data
{
    int l, r;
    bool operator<(const data& other) const
    {
        if (r - l != other.r - other.l) {
            return r - l < other.r - other.l;
        }
        return l < other.l;
    }
};

int main()
{

    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    set<data> q;
    string s;
    cin >> s;
    s += "1";

    int first = -1;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '1') {
            if (first != -1) {
                q.insert({first, i - 1});
                first = -1;
            }
        } else {
            if (first == -1) {
                first = i;
            }
        }
    }

    int curr = 0;
    for (auto it : q) {
        curr += (it.r - it.l + 1) / b;
    }

    vector<int> ans;

    while (curr >= a) {
        data d = *q.begin();
        q.erase(q.begin());
        if (d.r - d.l + 1 < b) {
            continue;
        }
        ans.pb(d.l + b - 1);
        if (d.l + b - 1 != d.r) {
            q.insert({d.l + b, d.r});
        }
        --curr;
    }

    sort(all(ans));
    cout << sz(ans) << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}