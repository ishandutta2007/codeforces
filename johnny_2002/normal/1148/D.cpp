#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 6e5 + 10;
int n;
int a[2][N];
vector<int> ans[2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        if (v1 < v2) a[0][v1] = i;
        else a[1][v2] = i;
    }
    for(int i = 2 * n; i >= 1; i--) if (a[0][i] > 0) 
        ans[0].push_back(a[0][i]);
    for(int i = 1; i <= 2 * n; i++) if (a[1][i] > 0) 
        ans[1].push_back(a[1][i]);
    int use = ans[1].size() >= ans[0].size();
    cout << ans[use].size() << '\n';
    for(auto i : ans[use]) cout << i << " ";
}