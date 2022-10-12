#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll d, k;
        cin >> d >> k;
        ll st = d * d / (2 * k * k);
        ll x = sqrt(st);
        while (x * x < st) x++;
        while (x * x > st) x--;
        st = x;
        //cout << st << "\n";
        if ((st + 1) * k * (st + 1) * k + st * k * st * k > d * d)
        {
            cout << "Utkarsh\n";
        }
        else
        {
            cout << "Ashish\n";
        }
    }
}