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

    int n;
    cin >> n;

    string s;
    cin >> s;
    map<char, int> mapa;
    for (int i = 0; i < sz(s); ++i) {
        ++mapa[s[i]];
    }

    int ans = 0;
    ans += 2 * min(mapa['U'], mapa['D']);
    ans += 2 * min(mapa['L'], mapa['R']);

    cout << ans << "\n";

}