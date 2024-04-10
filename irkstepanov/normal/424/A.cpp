#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector <int> vi;

const int inf = 1000000000;
const double eps = 0.000001;

int main()
{

    int n;
    cin >> n;
    string s;
    cin >> s;

    int X = 0, x = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'X') ++X;
        else ++x;

    cout << abs(X - x) / 2 << "\n";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'X' && X > x)
        {
            cout << 'x';
            --X;
            ++x;
        }
        else if (s[i] == 'x' && x > X)
        {
            cout << 'X';
            ++X;
            --x;
        }
        else cout << s[i];
    }

}