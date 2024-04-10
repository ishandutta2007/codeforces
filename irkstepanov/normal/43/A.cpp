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

    map<string, int> mapa;
    while (n--) {
        string s;
        cin >> s;
        ++mapa[s];
    }

    if (sz(mapa) == 1) {
        cout << mapa.begin()->first << "\n";
    } else {
        pair<string, int> a = *mapa.begin();
        pair<string, int> b = *(++mapa.begin());
        if (a.second > b.second) {
            cout << a.first << "\n";
        } else {
            cout << b.first << "\n";
        }
    }

}