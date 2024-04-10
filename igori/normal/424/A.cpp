#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <time.h>
//
using namespace std;
//
#define int long long
//
int n;
char c[5000];
int k, ans;
//
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> c;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 'X')
            k++;
    }
    ans = abs(k - n / 2);
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        if (k < n / 2 && c[i] == 'x')
        {
            c[i] = 'X';
            k++;
        }
        if (k > n / 2 && c[i] == 'X')
        {
            c[i] = 'x';
            k--;
        }
        cout << c[i];
    }
}