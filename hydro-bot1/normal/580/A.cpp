// Hydro submission #62550720ac286d0a56b85eb5@1649739552560
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n,a[100010],s=1,mx=1,i;
    cin>>n>>a[0];
    for(i=1;i<n;i++)
    {
    	cin>>a[i];
        if(a[i-1]>a[i])
		{
           	mx=max(mx,s);
         	s=1;
          	continue;
        }
        else if(i==n-1)
		mx=max(mx,s+1);
        else s++;
    }
    printf("%d\n",mx);
    return 0;
}