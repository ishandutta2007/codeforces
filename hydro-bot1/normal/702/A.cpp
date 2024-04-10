// Hydro submission #62550c8517cd4d0a41764c87@1649740933972
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    int n,i,mx=1,s=1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i&&a[i]>a[i-1]) s++;
        else mx=max(mx,s),s=1;
    }
    printf("%d\n",max(mx,s));
    return 0;
}