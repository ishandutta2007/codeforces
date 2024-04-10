#include <iostream>

using namespace std;
int x, n, i;
int main()
{
    cin >> n;
    for(i = 1; i <= n; ++i)
    {
        cin >> x;
        cout << 1 << ' ' << x-1<<'\n';
    }
    return 0;
}