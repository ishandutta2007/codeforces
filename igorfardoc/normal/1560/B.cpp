#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



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
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        --c;
        int n = abs(a - b) * 2;
        if(min(a, b) + n - max(a, b) != n / 2 || max(a, b) >= n)
        {
            cout << "-1\n";
            continue;
        }
        if(c >= n)
        {
            cout << "-1\n";
            continue;
        }
        cout << (c + max(b, a) - min(b, a)) % n + 1 << '\n';
    }
}