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
    //ofstream cout("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int a[21];
    a[1] = 0;
    set<int> s;

    for (int i = 2; i <= 20; ++i) {
        for (int x = 1; ; ++x) {
            bool ok = true;
            for (int j = 1; j < i; ++j) {
                if (s.count(a[j] + x)) {
                    ok = false;
                }
            }
            if (ok) {
                a[i] = x;
                for (int j = 1; j < i; ++j) {
                    s.insert(a[j] + a[i]);
                }
                break;
            }
        }
    }

    /*for (int i = 1; i <= 20; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";*/
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                cout << "0 ";
            } else {
                cout << a[i] + a[j] << " ";
            }
        }
        cout << "\n";
    }

}