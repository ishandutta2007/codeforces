#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s;
    cin >> s;

    for (int i = 0; i + 6 < s.size(); i++)
    if (s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == s[i + 3] && s[i] == s[i + 4] && s[i] == s[i + 5] && s[i] == s[i + 6]) {cout << "YES"; return 0;}

    cout << "NO";

}