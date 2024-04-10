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


int main () {
    string s;
    cin >> s;
    if (s == "0") {
        cout << "0\n";
        exit(0);
    }

    if (s.find('.') == string::npos) { // nie ma kropki
        s += '.';
    }

    // obetnij zera z konca
    while(s.back() == '0') {
        s.pop_back();
    }

    // obetnij zera z poczatku
    int start = 0;
    while (s[start] == '0')
        start++;
    s = s.substr(start, 99999999);

    // znajdz kropke
    int kropka = s.find('.');

    // znajdz pierwsza cyfre ktora nie jest zerem
    int pierwsze_niezero = 0;
    while (s[pierwsze_niezero] == '0' or s[pierwsze_niezero] == '.') {
        pierwsze_niezero++;
    }

    int e = kropka - pierwsze_niezero - 1;
    if (kropka < pierwsze_niezero) e = kropka - pierwsze_niezero;
    /*if (e == 0) {
        cout << s << "\n"; 
    }
    else*/ {
        string ans = "";
        ans = s[pierwsze_niezero];
        bool wstaw_kropke = false;
        for (int i = pierwsze_niezero+1; i < (int)s.size(); i++) {
            if (s[i] != '.' and s[i] != '0') {
                wstaw_kropke = true;
            }
        }
        if (wstaw_kropke) ans += ".";

        int koniec = (int)s.size();
        while ((s[koniec-1] == '0' or s[koniec-1] == '.') and koniec > 1)
            koniec--;

        for (int i = pierwsze_niezero+1; i < koniec; i++) {
            if (s[i] != '.') {
                ans += s[i];
            }
        }
        if (ans.back() == '.') ans.pop_back();
        if (e != 0) {
            ans += 'E';
            ans += to_string(e);
        }

        cout << ans << "\n";
    }

    return 0;
}