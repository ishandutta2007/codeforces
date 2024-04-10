// Hydro submission #62677afd255d14008c299f27@1650948861557
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    long long k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        printf(n%2-k%2||k*k>n?"NO\n":"YES\n");
    }
    return 0;
}