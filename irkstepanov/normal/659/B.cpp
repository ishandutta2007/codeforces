#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

struct man
{
    string name;
    int score;
    bool operator<(const man& other) const
    {
        if (score != other.score) {
            return score > other.score;
        }
        return false;
    }
};

int main()
{

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;

    vector<vector<man> > v(m);
    for (int i = 0; i < n; ++i) {
        string s;
        int t, x;
        cin >> s >> t >> x;
        --t;
        v[t].pb({s, x});
    }

    for (int i = 0; i < m; ++i) {
        sort(all(v[i]));
    }

    for (int i = 0; i < m; ++i) {
        bool ok = true;
        for (int j = 2; j < sz(v[i]); ++j) {
            if (v[i][j].score == v[i][1].score) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << v[i][0].name << " " << v[i][1].name << "\n";
        } else {
            cout << "?\n";
        }
    }

}