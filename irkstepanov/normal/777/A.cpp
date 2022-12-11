#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

int main()
{

	//freopen("input.txt", "r", stdin);
	//ifstream cin("input.txt");
    //ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, x;
    cin >> n >> x;

    n %= 6;
    int m[3] = {0, 1, 2};
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            swap(m[0], m[1]);
        } else {
            swap(m[1], m[2]);
        }
    }

    cout << m[x] << "\n";

}