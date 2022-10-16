#include <iostream>

using namespace std;

unsigned long long a1, a2, a3;
unsigned long long n, m, t, d;
/*
unsigned long long C(unsigned long long n, unsigned long long k)
{
    unsigned long long ans=1;

    for(unsigned long long i=k+1;i<=n;i++)
    {
        ans*=i;
    }

    for(unsigned long long i=1LL;i<=n-k;i++)
    {
        ans/=i;
    }
    return ans;
}
*/
unsigned long long C(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int main()
{
    cin >> n >> m >> t;

    unsigned long long ans = C(n+m, t);

    if(n>=t) ans-=C(n, t);
    for(int i=0;i<4;i++)
    {
        if(m < t-i) continue;
        ans -= 1LL*C(n, i)*C(m, t-i);
    }

    cout<<ans;

    return 0;
}