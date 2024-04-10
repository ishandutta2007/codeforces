#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m, inf);
    while (n--) {
        int r, c;
        cin >> r >> c;
        --r;
        a[r] = min(a[r], c);
    }

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += a[i];
    }
    cout << min(sum, k) << "\n";

}