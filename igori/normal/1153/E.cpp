#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long r[5000];
long long c[5000];
long long n;
vector<int> rodd;
vector<int> codd;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "? " << 1 << " " << i << " " << n << " " << i << endl;
        cin >> c[i];
        if (c[i] % 2)
            codd.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "? " << i << " " << 1 << " " << i << " " << n << endl;
        cin >> r[i];
        if (r[i] % 2)
            rodd.push_back(i);
    }
    if (rodd.size() == 2 && codd.size() == 2)
    {
        cout << "? " << rodd[0] << " " << codd[0] << " " << rodd[0] << " " << codd[0] << endl;
        int x;
        cin >> x;
        if (x % 2 == 0)
        {
            cout << "! " << rodd[0] << " " << codd[1] << " " << rodd[1] << " " << codd[0] << endl;
            return 0;
        }
        cout << "! " << rodd[0] << " " << codd[0] << " " << rodd[1] << " " << codd[1] << endl;
        return 0;
    }
    if (rodd.size() == 2)
    {
        long long l = 0, r = n;
        while (l + 1 < r)
        {
            long long mid = (l + r) / 2;
            cout << "? " << rodd[0] << " " << 1 << " " << rodd[0] << " " << mid << endl;
            int x;
            cin >> x;
            if (x % 2 == 0)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << "! " << rodd[0] << " " << r << " " << rodd[1] << " " << r << endl;
    }
    else
    {
        long long l = 0, r = n;
        while (l + 1 < r)
        {
            long long mid = (l + r) / 2;
            cout << "? " << 1 << " " << codd[0] << " " << mid << " " << codd[0] << endl;
            int x;
            cin >> x;
            if (x % 2 == 0)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        cout << "! " << r << " " << codd[0] << " " << r << " " << codd[1] << endl;
    }
}