#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<vector<int> > m(n, vector<int>(n, 0));

    vector<set<int> > row(n);
    for (int j = 1; j < n; ++j) {
        m[0][j] = m[j][0] = j;
    }

    for (int i = 1; i < n; ++i) {
        for (int k = 1; k < n; ++k) {
            if (k != i) {
                row[i].insert(k);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x = i + j;
            if (x >= n) {
                x -= n;
            }
            auto it = row[i].lower_bound(x);
            while (true) {
                if (it == row[i].end()) {
                    it = row[i].begin();
                    continue;
                }
                if (row[j].count(*it)) {
                    m[i][j] = m[j][i] = *it;
                    row[i].erase(it);
                    row[j].erase(m[i][j]);
                    break;
                }
                ++it;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

}