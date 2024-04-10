#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, z = 0, alfa, arr[10002];
    cin >> n >> alfa;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        z += arr[i];
        k = min(8, z);
        alfa -= k;
        z -= k;
        //cout << k << " " << z << endl;
        if (alfa <= 0)
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}