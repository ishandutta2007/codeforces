#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

struct team
{
    int x, y;
    int score;
    string name;
    bool operator<(const team& other) const
    {
        if (score != other.score) {
            return score > other.score;
        }
        if (x - y != other.x - other.y) {
            return x - y > other.x - other.y;
        }
        return x > other.x;
    }
};

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<team> m(n);
    map<string, int> num;
    for (int i = 0; i < n; ++i) {
        cin >> m[i].name;
        num[m[i].name] = i;
        m[i].x = m[i].y = m[i].score = 0;
    }

    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        string s;
        cin >> s;
        int pos = s.find('-');
        int a = num[s.substr(0, pos)];
        int b = num[s.substr(pos + 1, sz(s) - pos - 1)];
        cin >> s;
        pos = s.find(':');
        int x = atoi(s.substr(0, pos).c_str());
        int y = atoi(s.substr(pos + 1, sz(s) - pos - 1).c_str());
        m[a].x += x, m[a].y += y;
        m[b].x += y, m[b].y += x;
        if (x < y) {
            m[b].score += 3;
        } else if (x == y) {
            ++m[a].score, ++m[b].score;
        } else {
            m[a].score += 3;
        }
    }

    sort(all(m));
    vector<string> ans;
    for (int i = 0; i < n / 2; ++i) {
        ans.pb(m[i].name);
    }
    sort(all(ans));
    for (string& s : ans) {
        cout << s << "\n";
    }

}