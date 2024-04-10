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

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        b[i] = c - '0';
    }

    sort(all(a));
    sort(all(b));

    int ptr = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (ptr < n && b[ptr] < a[i]) {
            ++ptr;
        }
        if (ptr < n) {
            ++ptr;
        } else {
            ++ans;
        }
    }

    cout << ans << "\n";

    ans = 0;
    ptr = 0;
    for (int i = 0; i < n; ++i) {
        while (ptr < n && b[ptr] <= a[i]) {
            ++ptr;
        }
        if (ptr < n) {
            ++ptr;
            ++ans;
        }
    }

    cout << ans << "\n";

}