#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

int main()
{

    char a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int x1, y1, x2, y2;
    x1 = a1 - 'a' + 1;
    y1 = b1 - '0';
    x2 = a2 - 'a' + 1;
    y2 = b2 - '0';

    vector <string> ans;

    while (x1 != x2 || y1 != y2)
    {
        if (x1 < x2 && y1 < y2) {ans.pb("RU"); ++x1; ++y1;}
        else if (x1 < x2 && y1 > y2) {ans.pb("RD"); ++x1; --y1;}
        else if (x1 > x2 && y1 < y2) {ans.pb("LU"); --x1; ++y1;}
        else if (x1 > x2 && y1 > y2) {ans.pb("LD"); --x1; --y1;}
        else if (y1 < y2) {ans.pb("U"); ++y1;}
        else if (y1 > y2) {ans.pb("D"); --y1;}
        else if (x1 < x2) {ans.pb("R"); ++x1;}
        else {ans.pb("L"); --x1;}
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";

}