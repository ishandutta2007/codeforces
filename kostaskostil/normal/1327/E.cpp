#include <bits\stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long

using namespace std;

int m=998244353;
int bpow(int a, int b)
{
    if (b==0)
        return 1;
    if (b==1)
        return a;
    int x=bpow(a, b/2);
    int y=bpow(a, b%2);
    x*=x;
    x%=m;
    x*=y;
    x%=m;
    return x;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n-2; i++)
    {
        cout<< (2*9*bpow(10, n-i) + (n-i-1)*9*9*bpow(10, n-i-1))%m<<" ";
    }
    if (n>=2)
    cout<<"180 ";
    cout<<"10\n";
    return 0;
}