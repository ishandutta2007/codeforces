// Hydro submission #6247f3b30bc575b66aa57c05@1648882612770
#include<bits/stdc++.h>
using namespace std;
int h[100];
int main()
{
    int n,i,mn=1000;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>h[i];
    for(i=0;i<n-1;i++)
    if(abs(h[i+1]-h[i])<mn)
    mn=abs(h[i+1]-h[i]);
    mn=min(mn,abs(h[0]-h[n-1]));
    for(i=0;i<n-1;i++)
    if(abs(h[i+1]-h[i])==mn)
    {
        printf("%d %d\n",i+1,i+2);
        return 0;
    }
    printf("%d 1\n",n);
    return 0;
}