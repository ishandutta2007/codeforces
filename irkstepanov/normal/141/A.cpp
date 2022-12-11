#include <iostream>
#include <string>

using namespace std;

int main()
{

    int a[30], b[30];
    for (int i = 0; i < 30; i++)
        b[i] = a[i] = 0;

    string x, y, s;
    cin >> x >> y >> s;

    for (int i = 0; i < x.size(); i++)
        ++a[x[i] - 'A'];
    for (int i = 0; i < y.size(); i++)
        ++a[y[i] - 'A'];

    for (int i = 0; i < s.size(); i++)
        ++b[s[i] - 'A'];

    for (int i = 0; i < 30; i++)
        if (a[i] != b[i]) {cout << "NO"; return 0;}

    cout << "YES";

}