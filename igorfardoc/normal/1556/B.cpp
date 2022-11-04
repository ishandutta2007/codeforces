#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll do1(int start, vector<int>& a)
{
    ll res = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] % 2 == 0)
        {
            res += abs(start - i);
            start += 2;
        }
    }
    return res;
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
        vector<int> a(n);
        int a1 = 0;
        int a2 = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] % 2 == 0)
            {
                ++a1;
            }
            else
            {
                ++a2;
            }
        }
        if(abs(a1 - a2) > 1)
        {
            cout << "-1\n";
            continue;
        }
        if(a1 == a2)
        {
            cout << min(do1(0, a), do1(1, a));
        }
        else if(a1 > a2)
        {
            cout << do1(0, a);
        }
        else
        {
            cout << do1(1, a);
        }
        cout << '\n';
    }
}