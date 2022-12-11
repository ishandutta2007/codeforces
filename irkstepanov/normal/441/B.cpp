#include <bits/stdc++.h>

#define pb push_back

using namespace std;

struct type
{
    int a, b;
};

bool comp (type x, type y)
{
    return x.a < y.a;
}

int main()
{

    int n, v;
    cin >> n >> v;

    type t[4000];
    for (int i = 0; i < n; i++)
        cin >> t[i].a >> t[i].b;

    int ans = 0;
    int yes = 0, tod = 0;

    for (int d = 0; d < 5000; d++)
    {
        yes = tod;
        tod = 0;
        for (int i = 0; i < n; i++)
            if (t[i].a == d) tod += t[i].b;
        int add = min(yes, v);
        yes -= add;
        if (add < v)
        {
            int x = min(tod, v - add);
            tod -= x;
            add += x;
        }
        ans += add;
    }

    cout << ans;

}