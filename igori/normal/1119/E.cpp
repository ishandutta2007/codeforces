#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n;
ll a[500000];
ll summ = 0;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        summ += a[i];
    }
    long long ans = 0;
    long long have = 0;
    for (int i = 0; i < n; i++)
    {
        long long here = a[i];
        long long can_beat = min(a[i] / 2, have);
        long long res = have + here;
        for (int j = can_beat; j >= max(can_beat - 3, 0LL); j--)
        {
            long long leave = have - can_beat + (here - 2 * can_beat) % 3;
            res = min(res, leave);
        }
        have = res;
    }
    cout << (summ - have) / 3;
}