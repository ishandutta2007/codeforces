#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<int> zadaci[105];
int ispit[105];
int kad_ispit[105];
int ostalo[105];
int b[105];

void ne() {
    cout << "-1\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        zadaci[x].push_back(i);
        ispit[y] = i;
        kad_ispit[i] = y;
        ostalo[i] = z;
    }

    set<pair<int, int>> aktivni;

    for (int i=1; i<=n; i++) {
        for (int j : zadaci[i])
            aktivni.insert({kad_ispit[j], j});

        if (ispit[i]) {
            b[i] = m + 1;
            int y = ispit[i];
            if (ostalo[y] == 0) {
                aktivni.erase({kad_ispit[y], y});
            } else {
                ne();
            }
        } else {
            if (aktivni.size()) {
                int y = aktivni.begin()->second;
                ostalo[y]--;
                if (ostalo[y] == 0)
                    aktivni.erase({kad_ispit[y], y});
                b[i] = y;
            }
        }
    }

    if (aktivni.size())
        ne();

    for (int i=1; i<=n; i++)
        cout << b[i] << ' ';
    cout << '\n';


}