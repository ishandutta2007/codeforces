#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint n;
llint a[MAXN], b[MAXN], x[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        x[i] = max(x[i - 1], a[i - 1]);
        a[i] = b[i] + x[i];
        cout << a[i] << " ";
    }
    return 0;
}