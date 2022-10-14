#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n;
int deg[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++; deg[b]++;
    }
    for (int i=1; i<=n; i++) {
        if (deg[i] == 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}