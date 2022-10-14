#include <bits/stdc++.h>
using namespace std;

#ifdef D
#define deb printf
#define logg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    vars += ",";
    int pos1 = 0, pos2 = vars.find(',');
    ((cout << vars.substr(pos1, pos2-pos1) << ": " << values, pos1 = pos2, pos2 = vars.find(',', pos2+1)), ...);
    cout << endl;
}
#else
#define deb(...)
#define logg(...)
#endif
#define BOOST ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define pb push_back

typedef long long int ll;
typedef long double ld;

const int N = 0;

const string sym_list = "woxvWTYUIOHXVMA";
bool sym[500];

vector<string> odp_list = { "ww", "oo", "xx", "vv", "bd", "db", "pq", "qp", "WW", "TT", "YY", "UU", "II", "OO", "HH", "XX", "VV", "MM", "AA" };
char odp[500];

int main () {
    for (auto e : sym_list) 
        sym[(int)e] = true;
    for (auto e : odp_list) {
        odp[(int)e[0]] = e[1];
    }

    string s;
    cin >> s;
    int n = (int)s.size();
    if (n&1) {
        if (!sym[(int)s[n/2]]) {
            printf("NIE\n");
            exit(0);
        }
    }

    deb("n = %d\b", n);
    for (int i = 0; i < n/2; i++) {
        deb("rozpatruje pare %c i %c, odp = %c, %d\n", s[i], s[n-i-1], odp[(int)s[i]], odp[(int)s[n-i-1]]);
        if (odp[(int)s[i]] == 0 or odp[(int)s[i]] != s[n-i-1]) {
            printf("NIE\n");
            exit(0);
        }
    }

    printf("TAK\n");

    return 0;
}