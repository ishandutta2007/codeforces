#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }

    cout << max(0, maxx - 25) << "\n";

}