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

    if (s[0] == '-')
    {
        int a = (s[(int) s.size() - 1] - '0');
        int b = (s[(int) s.size() - 2] - '0');
        if (s.size() == 3 && min (a, b) == 0) {cout << 0; return 0;}
        for (int i = 0; i < s.size() - 2; i++)
            cout << s[i];
        cout << min (a, b);
    }

    else cout << s;

}