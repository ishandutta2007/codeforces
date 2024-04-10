#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "Tetrahedron")
        {
            x = x + 4;
        }
        if (s == "Cube")
        {
            x = x + 6;
        }
        if (s == "Octahedron")
        {
            x = x + 8;
        }
        if (s == "Dodecahedron")
        {
            x = x + 12;
        }
        if (s == "Icosahedron")
        {
            x = x + 20;
        }
    }
    cout << x;
}