#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

    map <string, int> res, tek;
    int n, i;
    string s[1200];
    int m[1200];

    cin >> n;

    for (i = 0; i < n; i++)
        cin >> s[i] >> m[i], res[s[i]] += m[i];

    int maxim = 0;
    for (i = 0; i < n; i++)
        maxim = max(maxim, res[s[i]]);

    for (i = 0; i < n; i++)
    {
        tek[s[i]] += m[i];
        if (tek[s[i]] >= maxim && res[s[i]] >= maxim) {cout << s[i]; return 0;}
    }

}