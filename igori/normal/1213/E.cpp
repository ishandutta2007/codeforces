#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>

using namespace std;

int n, m;
string s1, s2;

void ok(string s)
{
    for (int i = 0; i + 1 < s.size(); i++)
    {
        if (s[i] == s1[0] && s[i + 1] == s1[1])
            return;
        if (s[i] == s2[0] && s[i + 1] == s2[1])
            return;
    }
    cout << s;
    exit(0);
}

int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s1 >> s2;
    vector<char> c = {'a', 'b', 'c'};
    cout << "YES\n";
    for (int i = 0; i < 6; i++)
    {
        string s = "", t = "", ss = "";
        for (int j = 0; j < n; j++) s += c[0];
        for (int j = 0; j < n; j++) s += c[1];
        for (int j = 0; j < n; j++) s += c[2];
        ss += c[0];
        ss += c[1];
        ss += c[2];
        for (int j = 0; j < n; j++) t += ss;
        ok(s);
        ok(t);
        next_permutation(c.begin(), c.end());
    }
}