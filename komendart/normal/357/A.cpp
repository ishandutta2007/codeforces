#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;
    
    int sums[m + 1];
    sums[0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        int c;
        cin >> c;
        sums[i] = sums[i - 1] + c;
    }
    
    int x, y;
    cin >> x >> y;
    
    for (int i = 1; i <= m; ++i)
    {
        if (sums[i - 1] >= x && sums[i - 1] <= y &&
        sums[m] - sums[i - 1] >= x && sums[m] - sums[i - 1] <= y)
        {
            cout << i << endl;
            return 0;
        }
    }
    
    cout << 0 << endl;
    return 0;
}