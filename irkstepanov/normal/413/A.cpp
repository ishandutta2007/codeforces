#include <iostream>

using namespace std;

int main()
{

    int n, m, minim, maxim;
    int i;
    int t[120];
    bool ok = true;
    int addmin = 1, addmax = 1;

    cin >> n >> m >> minim >> maxim;

    for (i = 0; i < m; i++)
    {
        cin >> t[i];
        if (t[i] < minim) {ok = false; break;}
        if (t[i] > maxim) {ok = false; break;}
        if (t[i] == minim) addmin = 0;
        if (t[i] == maxim) addmax = 0;
    }

    if (!ok) {cout << "Incorrect"; return 0;}

    if (m + addmin + addmax <= n) {cout << "Correct"; return 0;}
    else cout << "Incorrect";

}