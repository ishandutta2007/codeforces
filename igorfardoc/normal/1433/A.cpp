#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string x;
        cin >> x;
        int ans = 0;
        ans += 10 * (x[0] - '1');
        ans += (x.size() * (x.size() + 1)) / 2;
        cout << ans << "\n";
    }
}