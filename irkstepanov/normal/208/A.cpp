#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    string s;
    cin >> s;

    for (int i = 0; i < (int) s.size() - 2; i++)
    {
        if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
        {
            s[i] = s[i + 1] = s[i + 2] = ' ';
        }
    }

    int pos = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ') {cout << s[i]; pos = 0;}
        else
        {
            if (pos == 0) {cout << ' '; pos = 1;}
        }
    }

}