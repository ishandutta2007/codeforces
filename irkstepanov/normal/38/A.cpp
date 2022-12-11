#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    vector<int> d(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> d[i];
    }
    int a, b;
    cin >> a >> b;
    --a, --b;

    int ans = 0;
    for (int i = a; i < b; ++i) {
        ans += d[i];
    }
    cout << ans << "\n";

}