#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    string s;
    int r;
    cin >> s >> r;
    if (s == "ABC" && r <= 1999) {
        cout << "YES\n";
    } else if (s == "ARC" && r <= 2799) {
        cout << "YES\n";
    } else if (s == "AGC" && r >= 1200) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}