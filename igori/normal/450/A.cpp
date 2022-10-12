#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cin  >> n >> m;
    int a[15000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int id = 0;
    int x = 0;
    while (id < 10000)
    {
        if (a[id] > 0)
        {
            a[id + n] = a[id] - m;
            x = id % n;
        }
        id++;
    }
    cout << x + 1;
}