#include <bits/stdc++.h>

#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

struct data
{
    ll c;
    bool post;
    bool operator<(const data& other) const
    {
        if (c != other.c) {
            return c < other.c;
        }
        if (post != other.post) {
            return !post;
        }
        return false;
    }
};

int main()
{

    //ifstream cin("input.txt");

    ll x;
    cin >> x;

    string s;
    cin >> s;

    vector<data> v;
    if (s[0] != '-') {
        s = "+" + s;
    }

    int pos = 0;

    while (pos < sz(s)) {
        int sgn = 1;
        if (s[pos] == '-') {
            sgn = -1;
        }
        ++pos;
        ll val = 1;
        if (isdigit(s[pos])) {
            val = 0;
            while (isdigit(s[pos])) {
                val *= 10;
                val += s[pos] - '0';
                ++pos;
            }
            ++pos;
        }
        bool post = true;
        if (s[pos] == 'a') {
            pos += 3;
        } else {
            post = false;
            pos += 3;
        }
        v.pb({val * sgn, post});
    }

    sort(all(v));

    ll ans = 0;
    for (int i = 0; i < sz(v); ++i) {
        if (!v[i].post) {
            ++x;
        }
        ans += v[i].c * x;
        if (v[i].post) {
            ++x;
        }
    }

    cout << ans << "\n";

}