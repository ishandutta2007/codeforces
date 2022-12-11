#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, i, j;
    char t, w;

    cin >> n;

    cin >> t >> w;

    bool ok = true;

    if (t == w) ok = false;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {if (i == 0 && j < 2) continue;
        char x;
        cin >> x;
        if ((i == j || i + j == n - 1) && x != t) ok = false;
        if (!(i == j || i + j == n - 1) && x != w) ok = false;}

    if (ok) cout << "YES";
    else cout << "NO";

}