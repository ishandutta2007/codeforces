#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;
int st[3][500000];
int dia, ver;

int main()
{
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        int r, c;
        cin >> r >> c;
        st[r][c] ^= 1;
        if (r == 1)
        {
            if (st[2][c] == 1)
            {
                if (st[1][c] == 1) ver++;
                else ver--;
            }
            if (st[2][c + 1] == 1)
            {
                if (st[1][c] == 1) dia++;
                else dia--;
            }
            if (st[2][c - 1] == 1)
            {
                if (st[1][c] == 1) dia++;
                else dia--;
            }
        }
        else
        {
            if (st[1][c] == 1)
            {
                if (st[2][c] == 1) ver++;
                else ver--;
            }
            if (st[1][c + 1] == 1)
            {
                if (st[2][c] == 1) dia++;
                else dia--;
            }
            if (st[1][c - 1] == 1)
            {
                if (st[2][c] == 1) dia++;
                else dia--;
            }
        }
        if (dia || ver)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
}