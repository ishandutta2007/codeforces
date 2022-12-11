#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

struct man
{
    int score;
    int cnt[50];
    string name;
    man(const string& s) : score(0), name(s)
    {
        for (int i = 0; i < 10; ++i) {
            cnt[i] = 0;
        }
    }
};

bool comp1(const man& a, const man& b)
{
    if (a.score != b.score) {
        return a.score > b.score;
    }
    for (int i = 0; i < 50; ++i) {
        if (a.cnt[i] != b.cnt[i]) {
            return a.cnt[i] > b.cnt[i];
        }
    }
    return false;
}

bool comp2(const man& a, const man& b)
{
    if (a.cnt[0] != b.cnt[0]) {
        return a.cnt[0] > b.cnt[0];
    }
    if (a.score != b.score) {
        return a.score > b.score;
    }
    for (int i = 1; i < 50; ++i) {
        if (a.cnt[i] != b.cnt[i]) {
            return a.cnt[i] > b.cnt[i];
        }
    }
    return false;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;
    map<string, int> m;
    vector<man> v;
    int d[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

    while (tt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (!m.count(s)) {
                m[s] = sz(v);
                v.pb(man(s));
            }
            if (i < 10) {
                v[m[s]].score += d[i];
            }
            ++v[m[s]].cnt[i];
        }
    }

    sort(all(v), comp1);
    cout << v[0].name << "\n";

    sort(all(v), comp2);
    cout << v[0].name << "\n";

}