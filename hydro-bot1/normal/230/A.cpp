// Hydro submission #6253c6beca53060146716076@1649657535133
#include<bits/stdc++.h>
using namespace std;
int x[1001],y[1001];
int main()
{
    int s,n,i,j;
    cin>>s>>n;
    for(i=0;i<n;i++)
    cin>>x[i]>>y[i];
    for(i=0;i<n;i++)
    for(j=0;j<n-i;j++)
    if(x[j]>x[j+1])
    {
        swap(x[j],x[j+1]);
        swap(y[j],y[j+1]);
    }
    for(i=1;i<=n;i++)
    if(s>x[i])
    s+=y[i];
    else
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}