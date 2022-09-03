#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x = i / 2;
        if (x % 2 == 0)
            cout << 'a';
        else
            cout << 'b';
    }
    return 0;
}