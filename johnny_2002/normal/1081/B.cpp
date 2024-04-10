#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];
vector<int> h[N];
int ans[N];

void solve() {
    int nc = 0;
    for(int i = 0; i < n; i++) if (h[i].size()) {
        int need = n - i; 
        if (h[i].size() % need != 0) {
            cout << "Impossible";
            return;
        }
        for(int j = 1; j <= h[i].size() / need; j++) {
            ++nc;
            for(int idx = (j - 1) * need; idx < j * need; idx++) 
                ans[h[i][idx]] = nc;
        }
    }
    cout << "Possible\n";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}
    
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) h[a[i]].push_back(i);
    solve();
}