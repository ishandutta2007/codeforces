#include<bits/stdc++.h>
using namespace std;

main()
{

    long long n;
    cin>>n;
    long long mak=0;
    for (long long i=n; i>0 && n-i<10; i--)
        for (long long j=n; j>0 && n-j<10; j--)
            for (long long k=n; k>0 && n-k<10; k--)
            {
                long long D=(i*j)/__gcd(i,j);
                long long E=(D*k)/__gcd(D,k);
                mak=max(mak, E);
            }
    cout <<mak<<endl;
}