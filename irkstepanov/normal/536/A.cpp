#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;

const ll inf = 1000000000ll;

ll a, b, t, m;
ll l;

bool ok(ll r)
{
    if (a + r * b > t) return false;
    if (a * (r - l + 1) + b * (r * (r + 1) / 2 - l * (l - 1) / 2) > t * m) return false;
    return true;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int q;
    scanf("%I64d %I64d %d", &a, &b, &q);

    while (q--)
    {
        scanf("%I64d %I64d %I64d", &l, &t, &m);
        --l;
        if (a + l * b > t) {cout << "-1\n"; continue;}
        ll x_left = l, x_right = inf;
        while (x_right - x_left > 1)
        {
            ll x = (x_left + x_right) / 2;
            if (ok(x)) x_left = x;
            else x_right = x - 1;
        }
        //cout << x_left << " " << x_right << "\n";
        if (ok(x_right)) cout << x_right + 1 << "\n";
        else cout << x_left + 1 << "\n";
    }

}