#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, arr[10002];
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + 2 * n);
    if (arr[n] != arr[n - 1])
        cout << "YES";
    else
        cout << "NO";
}