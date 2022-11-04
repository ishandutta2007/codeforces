#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x >= y)
        {
            cout << "yes" << endl;
            continue;
        }
        if (x == 1)
        {
            cout << "no" << endl;
            continue;
        }
        if (x == 2)
        {
            if (y != 3)
            {
                cout << "no" << endl;
                continue;
            }
        }
        if (x == 3)
        {
            cout << "no" << endl;
            continue;
        }
        cout << "yes" << endl;
    }
}