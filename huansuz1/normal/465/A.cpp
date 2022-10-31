#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 1, flag = 0;
    char k;
    
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == '0')
            flag = 1;
        else
        {
            if (flag == 0)
                ans++;
        }
    }
    if (ans > n)
        ans--;
    cout << ans;
    return 0;
}