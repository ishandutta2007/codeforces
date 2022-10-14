#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// void cer (...args) {
//     for (arg in args) {
//         cout << arg;
//     }
// }

struct Slowo {
    // poczatkowe 3 litery
    string pocz = "";
    // koncowe 3 litery
    string kon = "";

    // dlugosc Slowa
    ll dl = 0;

    ll ile_haha = 0;
};

map<string, Slowo> vars;

int licz_haha (string &s) {
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s.substr(i, 4) == "haha") {
            res++;
        }
    }
    return res;
}

int main () {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);


    int ttt;
    cin >> ttt;
    while (ttt--) {
        vars.clear();
        int n;
        cin >> n;
        string var, op;
        for (int ni = 0; ni < n; ni++) {
            cin >> var >> op;
            if (op == ":=") {
                string s;
                cin >> s;

                string pocz = "";
                for (int i = 0; i < 3 and i < (int)s.size(); i++) {
                    pocz += s[i];
                }


                string kon = "";
                for (int i = 0; i < 3 and i < (int)s.size(); i++) {
                    kon += s[s.size()-1-i];
                }
                reverse(kon.begin(), kon.end());

                //cerr << "pocz = " << pocz << ", kon = " << kon << endl;

                vars[var] = { pocz, kon, (ll)s.size(), licz_haha(s) };
            }
            else if (op == "=") {
                string rvar1, plus, rvar2;
                cin >> rvar1 >> plus >> rvar2;

                string dlugi_pocz = vars[rvar1].pocz + vars[rvar2].pocz;
                string pocz = "";
                for (int i = 0; i < 3 and i < (int)dlugi_pocz.size(); i++) {
                    pocz += dlugi_pocz[i];
                }

                string dlugi_kon = vars[rvar1].kon + vars[rvar2].kon;
                string kon = "";
                for (int i = 0; i < 3 and i < (int)dlugi_kon.size(); i++) {
                    kon += dlugi_kon[dlugi_kon.size()-1-i];
                }
                reverse(kon.begin(), kon.end());

                string srodek = vars[rvar1].kon + vars[rvar2].pocz;

                //cerr << "pocz = " << pocz << ", kon = " << kon << endl;

                ll dl = vars[rvar1].dl + vars[rvar2].dl;
                ll ile_haha = vars[rvar1].ile_haha
                              + vars[rvar2].ile_haha
                              + licz_haha(srodek);

                vars[var] = { pocz, kon, dl, ile_haha };
            }
        }

        cout << vars[var].ile_haha << "\n";
    }
	
	return 0;
}