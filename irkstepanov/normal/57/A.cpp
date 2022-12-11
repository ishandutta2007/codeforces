#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int f(int x, int y, int n) {
    if (y == 0) {
        return x;
    } else if (x == n) {
        return y + n;
    } else if (y == n) {
        return 3 * n - x;
    } else if (x == 0) {
        return 4 * n - y;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int c1 = f(x1, y1, n);
    int c2 = f(x2, y2, n);

    int ans = min(abs(c1 - c2), 4 * n - abs(c1 - c2));
    cout << ans << "\n";
    
}