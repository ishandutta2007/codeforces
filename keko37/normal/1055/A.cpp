#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, s;
int a[MAXN], b[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    if (a[1] == 0) {
        cout << "NO";
        return 0;
    }
    if (a[s] == 1) {
        cout << "YES";
        return 0;
    }
    if (b[s] == 0) {
        cout << "NO";
        return 0;
    }
    for (int i=s; i<=n; i++) {
        if (a[i] == 1 && b[i] == 1) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}