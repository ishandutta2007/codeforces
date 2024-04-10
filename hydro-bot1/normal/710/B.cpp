// Hydro submission #62550ceb17cd4d0a41764d10@1649741058333
#include<bits/stdc++.h>
using namespace std;
int x[300000];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>x[i];
    sort(x,x+n);
    printf("%d\n",n%2?x[n/2]:x[n/2-1]);
    return 0;
}