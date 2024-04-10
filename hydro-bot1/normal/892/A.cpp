// Hydro submission #62591dc7cc64917dc4665197@1650007495954
#include<bits/stdc++.h>
using namespace std;
int b[100000],mx,m;
long long s;
int main()
{
    int n,a,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a,s+=a;
    for(i=0;i<n;i++)
    {
        cin>>b[i];
        if(b[i]>mx)
        mx=b[i],j=i;
    }
    b[j]=0;
    for(i=0;i<n;i++)
    m=max(m,b[i]);
    if(s>mx+m) printf("NO\n");
    else printf("YES\n");
    return 0;
}