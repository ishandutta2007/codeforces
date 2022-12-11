#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main()
{

    string s;
    cin >> s;
    int pos = 0;
    char m[] = {'h', 'e', 'l', 'l', 'o'};

    for (int i = 0; i < s.size(); i++)
    {
        if (pos < 5 && s[i] == m[pos]) ++pos;
    }

    if (pos == 5) cout << "YES";
    else cout << "NO";

}