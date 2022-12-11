/**by Stepanov Ilia**/

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    int n;
    cin >> n;

    vector <int> l(n), a(n), len(n);

    int ans = 1;
    if (n > 1) ans = 2;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (!i)
        {
            l[i] = 0;
            len[i] = 1;
        }
        else
        {
            if (a[i] > a[i - 1]) {l[i] = l[i - 1]; ++len[l[i]]; len[i] = len[l[i]];}
            else {l[i] = i; len[i] = 1;}
        }
        ans = max(ans, len[i]);
    }

    if (n >= 3)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (a[i] >= a[i + 1]) ans = max(ans, len[i + 1] + 1);
                continue;
            }
            if (i == n - 1)
            {
                if (a[i] <= a[i - 1]) ans = max(ans, len[i - 1] + 1);
                continue;
            }
            if (a[i - 1] < a[i] && a[i] < a[i + 1])
                continue;
            if (a[i - 1] >= a[i] && a[i] >= a[i + 1])
            {
                if (a[i - 1] <= a[i + 1] - 2)
                    ans = max(ans, len[i - 1] + len[i + 1] + 1);
            }
            if (a[i] >= a[i + 1])
            {
                if (a[i - 1] < a[i + 1] - 1)
                    ans = max(ans, len[i + 1] + len[i]);
                ans = max(ans, len[i + 1] + 1);
            }
            if (a[i - 1] >= a[i])
            {
                if (a[i + 1] > a[i - 1] + 1)
                    ans = max(ans, len[i - 1] + len[i]);
                ans = max(ans, len[i - 1] + 1);
            }
        }
    }

    cout << ans;

}