// Hydro submission #6247f7260bc575b66aa58136@1648883495215
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n,l,i,j,s,mx=0;
    cin>>n>>l;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(j=l;j<=100;j++)
	{
		s=0;
		for(i=0;i<n;i++)
		s+=a[i]/j;
		if(s*j>mx) mx=s*j;
	}
    printf("%d\n",mx);
    return 0;
}