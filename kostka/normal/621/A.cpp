#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0, tmp = 0;
    for(int i=0; i<n; i++)
        tmp += a[i];
    if(tmp % 2 == 0)
        ans = tmp;
    for(int i=0; i<n; i++)
    {
        long long aaa = tmp - a[i];
        if(aaa % 2 == 0)
            ans = max(ans, aaa);
    }
    cout << ans << "\n";
}