#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int n, t;
    cin >> n >> t;

    char c[100];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    while (t--)
    {
        char r[100];
        for (int i = 0; i < n; i++)
            r[i] = c[i];
        for (int i = 0; i < n - 1; i++)
        if (c[i] == 'B' && c[i + 1] == 'G') {r[i] = 'G'; r[i + 1] = 'B';}
        for (int i = 0; i < n; i++)
            c[i] = r[i];
    }

    for (int i = 0; i < n; i++)
        cout << c[i];

}