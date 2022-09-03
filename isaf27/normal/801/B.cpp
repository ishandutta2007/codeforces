#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.size();
    string z = "";
    for (int i = 0; i < n; i++)
    {
        char r = y[i];
        char f = x[i];
        if (f < r)
        {
            cout << "-1";
            return 0;
        }
        z += r;
    }
    cout << z;
    return 0;
}