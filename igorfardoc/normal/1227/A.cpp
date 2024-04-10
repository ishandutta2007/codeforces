#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        long long lc = 100000000000;
        long long rc = -1000000000000;
        for(int i = 0; i < n; i++)
        {
            long long l, r;
            cin >> l >> r;
            rc = max(rc, l);
            lc = min(lc, r);
        }
        if (rc <= lc)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << rc - lc << endl;
        }
    }
}