#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        if (s.size() > 10)
        {
            cout << s[0] << (int) s.size() - 2 << s[(int) s.size() - 1] << "\n";
        }
        else cout << s << "\n";
    }

}