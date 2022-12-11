#include <iostream>
#include <string>

using namespace std;

int main()
{

    bool ok = true;
    string a = "", b = "";
    cin >> a;

    for (int i = 0; i < a.size(); i++)
    {
        char t = a[i];
        if (t == 'A' || t == 'H' || t == 'I' || t == 'M' || t == 'O' || t == 'T' || t == 'U' || t == 'V' || t == 'W' || t == 'X' || t == 'Y')
            b = t + b;
        else {ok = false; break;}
    }

    if (!ok) {cout << "NO"; return 0;}
    if (a == b) cout << "YES";
    else cout << "NO";

}