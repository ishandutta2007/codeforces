#include <iostream>
using namespace std;

int main() {
	// your code goes here
	  int n,m,a[123],b[123];
    cin>>n>>m;
    for (int i = 1; i <= m; ++i)
       cin>>a[i]>>b[i];

    int ans = -1;
    int t = 0;
    for (int i = 1; i <= 100; ++i)
    {
        bool flag = 1;
        for (int j = 1; j <= m; ++j)
        {
            if ((a[j] + i - 1) / i != b[j])
            {
                flag = 0;
                break;
            } 
        }
        if (flag)
        {

            if (ans == -1)
                ans = (n + i - 1) / i;
            else
            {
                if ((n + i - 1) / i != ans)
                {
                    t = 1;
                    break;
                }

            }
        }
    }

    if (t == 1)
        cout << -1 << endl;
    else
        cout << ans << endl;

	return 0;
}