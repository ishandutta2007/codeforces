#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int main()
{

    string s;
    cin >> s;

    if (s[0] >= '5' && s[0] <= '8') s[0] = (char) (9 - (s[0] - '0') + '0');

    for (int i = 1; i < sz(s); i++)
        if (s[i] >= '5') s[i] = (char) (9 - (s[i] - '0') + '0');

    cout << s << "\n";

}