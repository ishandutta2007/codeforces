#include <bits/stdc++.h>
 #define int long long
#define F first.first
#define S first.second
#define N second
using namespace std;

const int nmax=1001000;


main()
{
    int n;
    cin>>n;
    vector <bool> prime;
    prime.resize(n+10);
    for (int i=0; i<=n; i++)
        prime[i]=true;
    prime[0] = false;
    prime[1] = false;
    for (int i=2; i<=n; ++i)
        if (prime[i])
            if (i * i <= n)
                for (int j=i*i; j<=n; j+=i)
                {
                    prime[j] = false;
                }
   // for (int i=1; i<=n; ++i)
   //     if(prime[i])
   //         cout<<i<<prime[i]<<"\n";
    int j;
    for (j=1; j<(sqrt(n))+1; j++)
        if ((n%j==0) and (prime[n/j]))
            break;
    if (!((n%j==0) and (prime[n/j])))
    for (j=round(sqrt(n)+1); j>=1; j--)
    {
        //cout<<"lol";
        if ((n%j==0) and (prime[j]))
            break;
    }
    else j=n/j;
    j=n-j+1;
    //cout<<j;
    int mn=j;
    int i;
    for (i=j; ((i<n) and ((!prime[i/2]) or (i%2!=0))); i++)
    if (!prime[i])
    {
        for (int q=1; q<sqrt(i)+1; q++)
            if ((i%q==0) and (prime[i/q]==true))
                mn=min(mn,i-i/q+1);
        for (int q=1; q<sqrt(i)+1; q++)
            if ((i%q==0) and (prime[q]==true))
                mn=min(mn,i-q+1);
    }
    if ((i%2==0) and (prime[i/2]))
        mn=min(mn,i/2+1);
    cout<<mn<<"\n";
    return 0;
}