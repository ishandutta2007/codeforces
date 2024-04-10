#include <bits/stdc++.h>

using namespace std;

int main()
{
    int kase;
    cin >> kase;
    while (kase--)
    {
        int n;
        string s;
        cin >> n >> s;
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
    return 0;
}