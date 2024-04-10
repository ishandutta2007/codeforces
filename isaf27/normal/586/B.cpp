
#include <bits/stdc++.h>
 
using namespace std;
 
int n, pref[1000], prefd[1000], suff[1000], a[1000];
 
int main()
{
    cin >> n;
    pref[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        pref[i + 1] = a + pref[i];
    }
    prefd[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        prefd[i + 1] = a + prefd[i];
    }
    for (int i = n - 1; i >= 0; i--)
        suff[i] = prefd[n - 1] - prefd[i];
    int t = 1000000000;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                if (suff[i] + a[i] + pref[i] + pref[j] + a[j] + suff[j] < t)
                    t = suff[i] + a[i] + pref[i] + pref[j] + a[j] + suff[j];
    cout << t;
    return 0;
}