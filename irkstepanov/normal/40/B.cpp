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

int f(int n, int m) {
    if (n <= 0 || m <= 0) {
        return 0;
    }
    return (n * m + 1) / 2;
}

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
    int x;
    cin >> x;

    while (x > 1 && n > 0 && m > 0) {
        n -= 2, m -= 2;
        --x;
    }

    cout << f(n, m) - f(n - 2, m - 2) << "\n";

}