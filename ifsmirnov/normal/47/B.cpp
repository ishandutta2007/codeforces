#include <iostream>
#include <string>
using namespace std;

bool ab;
bool ac;
bool bc;

string index[1000];

void init()
{
    index[123] = "ABC";
    index[132] = "ACB";
    index[213] = "BAC";
    index[231] = "CAB";
    index[312] = "BCA";
    index[321] = "CBA";
};

void scan()
{
    string t;
    int hash;
    bool val;
    for (int i = 0; i < 3; i++)
    {
        cin >> t;
        hash = t[0] * 100 + t[2];
        if (t[1] == '>')
            val = 1;
        else
            val = 0;
        switch (hash)
        {
        case 'A' * 100 + 'B':
            ab = val;
            break;
        case 'B' * 100 + 'A':
            ab = !val;
            break;
        case 'A' * 100 + 'C':
            ac = val;
            break;
        case 'C' * 100 + 'A':
            ac = !val;
            break;
        case 'B' * 100 + 'C':
            bc = val;
            break;
        case 'C' * 100 + 'B':
            bc = !val;
            break;
        }
    }
};

void solve()
{
    for (int a = 1; a <= 3; a++)
        for (int b = 1; b <= 3; b++)
            for (int c = 1; c <= 3; c++)
            {
                if (a == b || a == c || b == c) continue;
                if (
                    ((a > b) == ab) &&
                    ((a > c) == ac) &&
                    ((b > c) == bc))
                {
                    cout << index[a * 100 + b * 10 + c];
                    return;
                }
            }
    cout << "Impossible";            
};

int main()
{
    //freopen("input.txt", "r", stdin);
    init();
    scan();
    solve();
    return 0;
}