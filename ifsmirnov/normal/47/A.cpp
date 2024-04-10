#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;
typedef long long ll;

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < 500; i++)
    {
        if (2 * n == i * (i + 1))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}