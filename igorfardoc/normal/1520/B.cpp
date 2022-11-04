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
        int res = 1;
        int now = 1;
        while(n >= (now = get_next(now)))
        {
            ++res;
        }
        cout << res << '\n';
    }
}