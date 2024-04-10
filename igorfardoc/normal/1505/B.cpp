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
    int a;
    cin >> a;
    int ans = 0;
    while(a >= 10)
    {
        ans = 0;
        while(a > 0)
        {
            ans += a % 10;
            a /= 10;
        }
        a = ans;
    }
    cout << a;
}