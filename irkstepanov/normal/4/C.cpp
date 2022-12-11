#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;

int main()
{

    map <string, int> m;
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        if (m.count(s)) cout << s << m[s];
        else cout << "OK";
        cout << "\n";
        ++m[s];
    }

}