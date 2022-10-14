#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int t, n;
int a[MAXN];
vector <vector <int> > v;

void f (int i, int j) {
    i++; j++;
    v.push_back({1, i, j});
    v.push_back({2, i, j});
    v.push_back({1, i, j});
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        v.clear();
        for (int i = 0; i < n; i += 2) {
            f(i, i + 1);
            f(i, i + 1);
        }
        cout << v.size() << '\n';
        for (int i = 0; i < v.size(); i++) {
            cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << '\n';
        }
    }
    return 0;
}