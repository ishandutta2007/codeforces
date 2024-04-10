// Hydro submission #62591ca637de167dd82bc5b2@1650007207561
#include<bits/stdc++.h>
using namespace std;
int p[200001],mx;
int main()
{
    int n,a,i,j,mn=200001;
    cin>>n;
    for(i=1;i<=n;i++)
	cin>>a,p[a]=i,mx=max(mx,a);
    for(i=0;i<=mx;i++)
    if(p[i]&&p[i]<mn)
    mn=p[i],j=i;
    printf("%d\n",j);
    return 0;
}