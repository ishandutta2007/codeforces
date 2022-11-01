#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int tp;
string s;
int bd;
string bu;

int main() {
    cin >> tp >> s;
    int mn = tp == 12 ? 1 : 0;
    int mx = tp == 12 ? 13 : 24;
    bd = 1e9;
    FO(i,mn,mx) {
        FO(j,0,60) {
            stringstream o;
            if (i < 10) o << '0';
            o << i << ":";
            if (j < 10) o << '0';
            o << j;

            string u = o.str();

            int df = 0;
            FO(i,0,5) df += u[i] != s[i];
            if (df < bd) {
                bd = df;
                bu = u;
            }
        }
    }
    cout << bu << "\n";
}