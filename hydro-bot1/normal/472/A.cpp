// Hydro submission #625504d3ac286d0a56b8579d@1649738963405
#include<bits/stdc++.h>
using namespace std;
bool su(int x)
{
    if(x<2) return false;
    for(int i=2;i<=sqrt(x);i++)
    if(x%i==0) return false;
    return true;
}
int main()
{
    int n,j;
    cin>>n;
    for(j=4;j<=n/2;j++)
    if(!su(j)&&!su(n-j))
    {
        printf("%d %d\n",j,n-j);
        return 0;
    }
    return 0;
}