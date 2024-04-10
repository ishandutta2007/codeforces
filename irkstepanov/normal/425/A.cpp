#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, k;
    int a[220];
    int ans = -9999999;

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
    {
        vector <int> otr, ost;
        for (int g = 1; g <= n; g++)
            if (g >= i && g <= j) otr.push_back(a[g]);
            else ost.push_back(a[g]);
        sort (ost.begin(), ost.end());
        sort (otr.begin(), otr.end());
        int uotr = 0, uost = (int) ost.size() - 1;
        while (uotr < otr.size() && uost >= 0 && uotr < k && otr[uotr] < ost[uost])
        {
            otr[uotr] = ost[uost];
            uotr++;
            uost--;
        }
        int sum = 0;
        for (int g = 0; g < otr.size(); g++)
            sum += otr[g];
        ans = max (ans, sum);
    }

    cout << ans;
}