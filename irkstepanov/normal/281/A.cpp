#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    string s;
    cin >> s;

    if (s[0] >= 'a' && s[0] <= 'z') cout << (char) ((s[0] - 'a') + 'A');
    else cout << s[0];

    for (int i = 1; i < s.size(); i++)
        cout << s[i];

}