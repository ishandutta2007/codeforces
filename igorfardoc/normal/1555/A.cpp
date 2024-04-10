#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get(ll ch)
{
    if(ch <= 0)
    {
        return 0;
    }
    return ((ch - 1) / 6 + 1) * 15;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << min(get(n), min(get(n - 8) + 20, get(n - 10) + 25)) << '\n';
    }
}