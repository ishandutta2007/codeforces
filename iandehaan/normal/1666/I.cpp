#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;

#define pb push_back
#define mp make_pair

int query(int x, int y) {
    cout << "SCAN " << x+1 << ' ' << y+1 << endl;
    int out;
    cin >> out;
    return out;
}

int dig(int x, int y) {
    cout << "DIG " << x+1 << ' ' << y+1 << endl;
    int out;
    cin >> out;
    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int a = query(0, 0);
        int b = query(0, m-1);

        int xsum = (a + b - 2*m + 2) / 2;
        int ysum = a - xsum;

        int c = query(xsum/2, 0);
        int xminus = c - ysum;
        int doublex2 = xminus + xsum;
        int x2 = doublex2/2;
        int x1 = xsum - x2;

        int d = query(0, ysum/2);
        int yminus = d - xsum;
        int doubley2 = yminus + ysum;
        int y2 = doubley2/2;
        int y1 = ysum - y2;

        int r1 = dig(x1, y1);
        if (r1 == 1) {
            int r2 = dig(x2, y2);
            if (r2 != 1) return 1;
        } else {
            int r2 = dig(x1, y2);
            int r3 = dig(x2, y1);
            if (r2 + r3 != 2) return 1;
        }
    }
}