#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int get_next(int a)
{
    int last = a % 10;
    if(last != 9)
    {
        return a / last * (last + 1);
    }
    return a / last * 10 + 1;
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
        int n;
        cin >> n;
        if(n == 2)
        {
            cout << -1 << '\n';
            continue;
        }
        int now = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << now << ' ';
                now += 2;
                if(now > n * n)
                {
                    now = 2;
                }
            }
            cout << '\n';
        }
    }
}