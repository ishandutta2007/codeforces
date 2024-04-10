// Hydro submission #6253d885ca53060146717b51@1649662085509
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    float x,y,s=0;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>x>>y,s+=y;
    printf("%.3f\n",s/n+5);
    return 0;
}