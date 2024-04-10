#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    string s;
    cin >> s;
    int kol = 0;

    for (int i = 0; i < s.size(); i++)
        kol += ((s[i] == '4') || (s[i] == '7'));

    cout << (kol == 4 || kol == 7 ? "YES" : "NO");

}