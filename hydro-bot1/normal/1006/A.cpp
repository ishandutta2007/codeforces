// Hydro submission #625cea0bfa9408d417fea882@1650256396143
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        printf("%d ",a%2?a:a-1);
    }
    return 0;
}