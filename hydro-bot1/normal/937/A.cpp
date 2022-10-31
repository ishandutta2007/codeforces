// Hydro submission #62592040cc64917dc46652f7@1650008129102
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n,i,j,s=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
		if(!a[i]) s++;
        else for(j=0;j<i;j++)
        if(a[i]==a[j])
        {
            s++;
            break;
        }
    }
    printf("%d\n",n-s);
    return 0;
}