#include <iostream>
#include <vector>

#define int long long
#define pb push_back

using namespace std;
typedef long long ll;

const int INFLL = 3e18 + 1;

ll n, s;
ll a, c3, c4, c5, k3, k4, k5;
ll ans = INFLL, Ak3, Ak4, Ak5;

double abss(double x)
{
    if (x >= 0)
        return x;
    return -x;
}

ll f(int k3, int k4, int k5)
{
    if (!(k3 <= k4 && k4 <= k5))
        return INFLL;
    if (k3 < 0)
        return INFLL;
    return abss(k3 * c3 - k4 * c4) + abss(k5 * c5 - k4 * c4);
}

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<int, int> gcdext(int a, int b)
{
    if (a == 0)
    {
        return {0, 1};
    }
    pair<int, int> XY = gcdext(b % a, a);
    pair<int, int> nXY;
    nXY.first = XY.second - (b / a) * XY.first;
    nXY.second =  XY.first;
    return nXY;
}

ll myFind(ll mn, ll d, ll izn)
{
    ll a = (mn - izn) / d + ((mn - izn) % d > 0);
    return a;
}

int v[8];

signed main()
{
    //freopen("stdin.in", "r", stdin);
    //freopen("stdout.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 3)
            c3++;
        if (a == 4)
            c4++;
        if (a == 5)
            c5++;
    }
    ll g = gcd(c3, c5);
    for (int k4 = 0; k4 <= s; k4++)
    {
        ll r = s - k4 * c4;
        if (r <= 0)
            continue;
        if (r % g != 0)
            continue;
        //k3 * c3 + k5 * c5 == r
        int a = c3 / g;
        int b = c5 / g;
        pair<int, int> XY = gcdext(a, b);
        ll k3 = XY.first * r / g;
        ll k5 = XY.second * r / g;
        //we can add a to k5 and -b to k3 both
        ll w = k4 * c4;
        v[0] = (myFind(w, b * c3, k3 * c3));
        v[1] = (myFind(w, b * c3, k3 * c3) - 1);
        v[2] = (myFind(w, -a * c5, k5 * c5));
        v[3] = (myFind(w, -a * c5, k5 * c5) - 1);
        v[4] = (myFind(0, b, k3));
        v[5] = (myFind(k4, b, k3));
        if (v[5] * b + k3 > k4)
            v[5]--;
        v[6] = myFind(k4, -a, k5);
        for (int ii = 0; ii < 7; ii++)
        {
            int i = v[ii];
            k3 = k3 + i * b;
            k5 = k5 - i * a;
            if (f(k3, k4, k5) < ans)
            {
                ans = f(k3, k4, k5);
                Ak3 = k3;
                Ak4 = k4;
                Ak5 = k5;
            }
            k3 = k3 - i * b;
            k5 = k5 + i * a;
        }
    }
    if (ans == INFLL)
    {
        cout << -1;
    }
    else
    {
        //cout << c3 << " " << c4 << " " << c5 << endl;
        cout << Ak3 << " " << Ak4 << " " << Ak5 << endl;
        //cout << ans << endl;
    }
}