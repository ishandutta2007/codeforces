#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s;
    getline (cin, s);

    for (int i = 0; i < s.size(); i++)
    if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {cout << "YES"; return 0;}

    cout << "NO";

}