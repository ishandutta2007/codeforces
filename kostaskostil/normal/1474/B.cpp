#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 5e5+100;

set<int> primes;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=2; i<=100000; i++)
    {
        bool ok=true;
        for (int j=2; j*j<=i; j++)
            if (i%j==0)
                ok=false;
        if (ok)
            primes.insert(i);
    }

    int ___;
    cin>>___;
    for (int _=0; _<___; _++)
    {
        int d;
        cin>>d;
        int p1 = *primes.lower_bound(d+1);
        int p2 = *primes.lower_bound(d+p1);
        cout<<p1*p2<<"\n";
    }

	return 0;
}