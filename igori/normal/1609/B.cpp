#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> pos(n);
    for (int i = 0; i + 2 < s.size(); i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
        {
            pos[i] = 1;
            cnt++;
        }
    }
    while (q--)
    {
        int x;
        char c;
        cin >> x >> c;
        x--;
        s[x] = c;
        for (int i = max(0, x - 2); i + 2 < s.size() && i <= x; i++)
        {
            cnt -= pos[i];
            pos[i] = 0;
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            {
                pos[i] = 1;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}