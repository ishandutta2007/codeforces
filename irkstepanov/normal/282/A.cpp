#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int x = 0;

    while (n--)
    {
        string s;
        cin >> s;
        if (s[1] == '-') x--;
        else x++;
    }

    cout << x;

}