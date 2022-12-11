#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    map<char, char> m;
    m['A'] = 'A';
    m['b'] = 'd';
    m['d'] = 'b';
    m['H'] = 'H';
    m['I'] = 'I';
    m['M'] = 'M';
    m['O'] = 'O';
    m['o'] = 'o';
    m['p'] = 'q';
    m['q'] = 'p';
    m['T'] = 'T';
    m['U'] = 'U';
    m['V'] = 'V';
    m['v'] = 'v';
    m['W'] = 'W';
    m['w'] = 'w';
    m['X'] = 'X';
    m['x'] = 'x';
    m['Y'] = 'Y';

    for (int i = 0; i < sz(s); ++i) {
        int j = sz(s) - i - 1;
        if (!m.count(s[i]) || s[j] != m[s[i]]) {
            cout << "NIE\n";
            return 0;
        }
    }

    cout << "TAK\n";

}