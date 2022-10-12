#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define sz size()
#define re return

typedef long long ll;

ll n, v1, v2, L, k;
ll m, v, VB, MB;

bool c(double mid)
{
    //m * x = mid * v
    double l1 = 0, r1 = 1e9;
    ll it2 = 50;
    double x = 0;
    while (it2 > 0)
    {
        double midl = (l1 + r1) / 2;
        double time = (midl * m) / v + (midl * MB) / VB;
        //cout << midl << " " << time << endl;
        if (time > mid)
        {
            r1 = midl;
        }
        else
        {
            l1 = midl;
        }
        it2--;
    }
    x = l1;
    double more = v1 * mid;
    //cout << v1 << " " << mid << endl;
    //cout << more << " " << x << endl;
    if (x + more >= L)
        re 1;
    re 0;
}

int main()
{
    cin >> n >> L >> v1 >> v2 >> k;
    m = n / k + (n % k > 0);
    v = v2 - v1;
    VB = v2 + v1;
    MB = m - 1;
    //cout << m << endl;
    double l = 0, r = 1e9;
    ll it = 50;
    while (it--)
    {
        double mid = (l + r) / 2;
        if (c(mid) == 1)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    printf("%.9f", min(r, (double)L / v1));
}