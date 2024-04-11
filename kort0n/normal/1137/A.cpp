#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
int n, m;
int a[1050][1050];
vector<int> column[1050];
vector<int> row[1050];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            column[j].push_back(a[i][j]);
            row[i].push_back(a[i][j]);
        }
    }
    for(int i = 1; i <= m; i++) {
        sort(column[i].begin(), column[i].end());
        column[i].erase(unique(column[i].begin(), column[i].end()), column[i].end());
    }
    for(int i = 1; i <= n; i++) {
        sort(row[i].begin(), row[i].end());
        row[i].erase(unique(row[i].begin(), row[i].end()), row[i].end());
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int val = a[i][j];
            int before1 = distance(column[j].begin(), lower_bound(column[j].begin(), column[j].end(), val));
            int before2 = distance(row[i].begin(), lower_bound(row[i].begin(), row[i].end(), val));
            int after1 = column[j].size() - 1 - before1;
            int after2 = row[i].size() - 1 - before2;
            //cout << i << " " << j << " " << before1 << " " << before2 << " " << after1 << " " << after2 << endl;
            cout << max(before1, before2) + 1 + max(after1, after2);
            if(j < m) cout << " ";
        }
        cout << endl;
    }
    return 0;
}