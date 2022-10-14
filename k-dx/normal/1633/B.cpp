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

int n;
int t[4];

int main () {
    // BOOST;
    int ttt;
    cin >> ttt;
    while (ttt--) {
        t[0] = 0;
        t[1] = 0;

        string s;
        cin >> s;

        int w = 0;
        if (s.size() == 1 or s.size() == 2) {
            w = 0;
        }
        else {

            for (char e : s)
                t[e - '0']++;

            if (t[0] != t[1]) {
                w = min(t[0], t[1]);
            }
            else {
                // obetnij poz 0
                t[s[0] - '0']--;
                int min1  = min(t[0], t[1]);
                t[s[0] - '0']++;

                t[s.back() - '0']--;
                int min2  = min(t[0], t[1]);
                t[s.back() - '0']++;

                w = max(min1, min2);
            }
        }

        cout << w << "\n";
    }

    return 0;
}