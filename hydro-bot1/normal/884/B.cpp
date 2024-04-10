// Hydro submission #62591c95cc64917dc46650e9@1650007189460
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,a,i,s=0;
    cin>>n>>x;
    for(i=0;i<n;i++)
    cin>>a,s+=a;
    if(s==x-n+1) printf("YES\n");
    else printf("NO\n");
    return 0;
}