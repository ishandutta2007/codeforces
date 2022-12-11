#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
#include <cstdlib>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;

int main()
{

    string s;
    cin >> s;

    for (int i = 1; i <= (int) s.size() - 3; i++)
        if (s[i] == 'a' && s[i + 1] == 't')
        {
            s[i] = '@';
            s[i + 1] = '\0';
            break;
        }

    for (int i = 1; i <= (int) s.size() - 4; i++)
    {
        if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't')
        {
            s[i] = '.';
            s[i + 1] = '\0';
            s[i + 2] = '\0';
        }
    }

    for (int i = 0; i < s.size(); i++)
        if (s[i] != '\0') cout << s[i];

}