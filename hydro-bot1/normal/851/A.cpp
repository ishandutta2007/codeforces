// Hydro submission #62591b0ecc64917dc4664f9a@1650006799203
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,t;
    cin>>n>>k>>t;
    printf("%d\n",t<k?t:t<n?k:n+k-t);
    return 0;
}