#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;
const int MAXM = 1005;

int n, m;
int a[MAXN], cnt[MAXM];

int mul (int x, int y) {return (llint) x * y % m;}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] % m]++;
    }
    for (int i = 0; i < m; i++) {
        if (cnt[i] >= 2) {
            cout << 0;
            return 0;
        }
    }
    int sol = 1 % m;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sol = mul(sol, abs(a[i] - a[j]) % m);
        }
    }
    cout << sol;
    return 0;
}