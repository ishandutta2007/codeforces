#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n == 1) {
        if (m == 2) {
            cout << "0\n";
            cout << "1 1\n";
            cout << "1 2\n";
            cout << "1 1\n";
            return 0;
        }
        cout << "1\n";
        cout << "1 " << m << " 1 1" << "\n";
        for (int j = 1; j <= m; ++j) {
            cout << "1 " << j << "\n";
        }
        cout << "1 1\n";
        return 0;
    }

    if (m == 1) {
        if (n == 2) {
            cout << "0\n";
            cout << "1 1\n";
            cout << "2 1\n";
            cout << "1 1\n";
            return 0;
        }
        cout << "1\n";
        cout << n << " 1 1 1\n";
        for (int i = 1; i <= n; ++i) {
            cout << i << " " << 1 << "\n";
        }
        cout << "1 1\n";
        return 0;
    }

    if (n % 2 == 0) {
        cout << "0\n";
        for (int j = 1; j <= m; ++j) {
            cout << "1 " << j << "\n";
        }
        for (int i = 2; i <= n; ++i) {
            if (i % 2 == 0) {
                for (int j = m; j >= 2; --j) {
                    cout << i << " " << j << "\n";
                }
            } else {
                for (int j = 2; j <= m; ++j) {
                    cout << i << " " << j << "\n";
                }
            }
        }
        for (int i = n; i >= 1; --i) {
            cout << i << " 1\n";
        }
        return 0;
    }

    if (m % 2 == 0) {
        cout << "0\n";
        for (int i = 1; i <= n; ++i) {
            cout << i << " 1\n";
        }
        for (int j = 2; j <= m; ++j) {
            if (j % 2 == 0) {
                for (int i = n; i >= 2; --i) {
                    cout << i << " " << j << "\n";
                }
            } else {
                for (int i = 2; i <= n; ++i) {
                    cout << i << " " << j << "\n";
                }
            }
        }
        for (int j = m; j >= 1; --j) {
            cout << "1 " << j << "\n";
        }
        return 0;
    }

    cout << "1\n";
    cout << n << " " << m << " 1 1\n";
    for (int j = 1; j <= m; ++j) {
        if (j % 2 == 1) {
            for (int i = 1; i <= n; ++i) {
                cout << i << " " << j << "\n";
            }
        } else {
            for (int i = n; i >= 1; --i) {
                cout << i << " " << j << "\n";
            }
        }
    }
    cout << "1 1\n";

}