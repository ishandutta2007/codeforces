#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    int i;
    int l = -2000000000, r = 2000000000;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        string s;
        int x;
        char ans;
        cin >> s >> x >> ans;
        if (s == ">")
        {
            if (ans == 'N') r = min(r, x);
            else l = max(l, x + 1);
        }
        if (s == "<")
        {
            if (ans == 'N') l = max(l, x);
            else r = min(r, x - 1);
        }
        if (s == ">=")
        {
            if (ans == 'Y') l = max(l, x);
            else r = min(r, x - 1);
        }
        if (s == "<=")
        {
            if (ans == 'Y') r = min(r, x);
            else l = max(l, x + 1);
        }
    }

    if (l <= r) cout << l;
    else cout << "Impossible";

}