#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] = (char) ((s[i] - 'A') + 'a');
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'y' || s[i] == 'u' || s[i] == 'i' || s[i] == 'o') continue;
        else cout << '.' << s[i];
    }

}