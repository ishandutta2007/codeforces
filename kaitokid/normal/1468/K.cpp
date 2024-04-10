#include <bits/stdc++.h>

using namespace std;

set <pair <int, int> > myset;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int x = 0, y = 0;
        int n = s.length();
        myset.clear();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;
            if (s[i] == 'R') x++;
            if (s[i] == 'L') x--;
            myset.insert({x, y});
        }
        int X = 0, Y = 0;
        for (auto u: myset) {
            if (X != 0 || Y != 0) break;
            int A = u.first, B = u.second;
            int x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                int tmpX = x, tmpY = y;
                if (s[i] == 'U') tmpY++;
                if (s[i] == 'D') tmpY--;
                if (s[i] == 'R') tmpX++;
                if (s[i] == 'L') tmpX--;
                if (tmpX == A && tmpY == B) continue;
                else x = tmpX, y = tmpY;
            }
            if (x == 0 && y == 0)
                X = A, Y = B;
        }
        cout << X << ' ' << Y << endl;
    }
    return 0;
}