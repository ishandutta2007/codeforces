#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<deque<int> > pos(3);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - '0'].pb(i);
    }

    for (int i = 0; i < 3; ++i) {
        if (sz(pos[i]) > n / 3) {
            vector<int> ord = {0, 1, 2};
            if (i == 0) {
                ord = {2, 1};
            }
            for (int j : ord) {
                while (sz(pos[i]) > n / 3 && sz(pos[j]) < n / 3) {
                    if (i > j) {
                        int x = pos[i].front();
                        s[x] = char(j + '0');
                        pos[i].pop_front();
                        pos[j].pb(x);
                    } else {
                        int x = pos[i].back();
                        s[x] = char(j + '0');
                        pos[i].pop_back();
                        pos[j].pb(x);
                    }
                }
            }
        }
    }

    cout << s << "\n";

}