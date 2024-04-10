// Hydro submission #6247f27d993deab6561072cf@1648882302573
#include<bits/stdc++.h>
using namespace std;
int a[1000],s1,s2;
int main()
{
    int n,d,i,j;
    cin>>n>>d;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    //if(a[i]==a[j])
    //s1++,printf("%d+/2\n",s1);
    //else 
	if(a[i]-a[j]<=d&&a[i]-a[j]>=-d)
    s2++;//printf("%d++\n",s2);
    printf("%d\n",s2*2+s1);
    return 0;
}