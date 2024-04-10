#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s;
    cin >> s;

    bool ok = true;
    for (int i = 1; i < s.size(); i++)
        if (!(s[i] >= 'A' && s[i] <= 'Z')) ok = false;

    if (ok)
    {
        for (int i = 0; i < s.size(); i++)
        {
            char t = s[i];
            if (t >= 'a' && t <= 'z') cout << (char) ((t - 'a') + 'A');
            else cout << (char) ((t - 'A') + 'a');
        }
    }

    else
    cout << s;

}