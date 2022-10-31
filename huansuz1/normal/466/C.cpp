#include <iostream>
#include <math.h>

using namespace std;

int a[1000010];
long long cnt[1000010];

int main()
{
    int n;
    cin >> n;
    long long s = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0)
        cout << "0\n";
    else {
        s /= 3;
        long long ss = 0 , x = 0 , ans = 0;
        for(int i = 0; i < n-1 ; i++)
        {
            ss += a[i];
            if (ss == s * 2)
                ans += x;
            if (ss == s) 
                x++;
        }
        cout<<ans;

    }
    return 0;
}