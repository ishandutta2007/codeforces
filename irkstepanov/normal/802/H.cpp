#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("./python/input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ord;
    while (n > 2) {
        ord.pb(n);
        if (n % 2 == 0) {
            n = n / 2 - 1;
        } else {
            n = n / 2;
        }
    }

    string s, p;
    if (n == 1) {
        s = "a";
        p = "a";
    } else {
        s = "aa";
        p = "a";
    }

    reverse(all(ord));
    char c = 'b';
    for (int i = 0; i < sz(ord); ++i) {
        string u = s.substr(sz(p), sz(s) - sz(p));
        if (ord[i] == 2 * n + 1) {
            s = p + c + u + c + c;
        } else {
            s = p + c + c + u + c + c;
        }
        p += c;
        ++c;
        n = ord[i];
    }

    cout << s << " " << p << "\n";

}