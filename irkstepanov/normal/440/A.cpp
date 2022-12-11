#include <iostream>

using namespace std;

int used[100500];

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        used[x] = 1;
    }

    for (int i = 1; i <= n; i++)
        if (!used[i]) cout << i;

}