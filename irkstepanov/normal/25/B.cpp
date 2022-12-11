#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("division.in");
    //ofstream cout("division.out");

    int n;
    string s;
    cin >> n >> s;

    int pos;
    if (n % 2 == 0) {
        cout << s[0] << s[1];
        pos = 2;
    } else {
        cout << s[0] << s[1] << s[2];
        pos = 3;
    }

    for (; pos < n; pos += 2) {
        cout << "-";
        cout << s[pos] << s[pos + 1];
    }
    cout << "\n";

}