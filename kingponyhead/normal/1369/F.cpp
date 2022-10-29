// Screw this ..
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int Solve(ll l, ll r)
{
    if (r < l)
        return 1;
    if (r & 1LL)
        if (l & 1LL)
            return 0;
        else
            return 1;
    if (l > r / 2)
        return (l & 1);
    if (l > r / 4)
        return 1;
    return Solve(l, r / 4);
}
int main()
{
    int n;
    scanf("%d", &n);
    int Cn1 = 1, Cn2 = 0;
    for (; n; n --)
    {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        int Tn1 = 0, Tn2 = 0;
        if (Solve(l, r))
            Tn2 |= Cn1;
        else
            Tn2 |= Cn2;
        if (l * 2 > r || Solve(l, r / 2))
            Tn1 |= Cn1;
        else
            Tn1 |= Cn2;
        Cn1 = Tn1;
        Cn2 = Tn2;
    }
    return !printf("%d %d\n", Cn2, Cn1);
}