#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    if (k > (n - 1) / 2) {cout << "-1"; return 0;}

    cout << n * k << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= i + k; j++)
        {
            cout << i << " ";
            if (j > n) cout << j - n;
            else cout << j;
            cout << "\n";
        }
    }

}