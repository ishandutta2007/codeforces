#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int d[120];
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        sum += d[i];
    }

    int a, b;
    cin >> a >> b;

    int x = 0;
    while (a != b)
    {
        x += d[a];
        ++a;
        if (a > n) a -= n;
    }

    cout << min(x, sum - x);

}