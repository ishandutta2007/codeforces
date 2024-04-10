// Hydro submission #625ced81fa9408d417feaa8d@1650257282449
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
    while(a-x&&b-y)
    {
        if(a==n) a=1;
        else a++;
        if(b==1) b=n;
        else b--;
        if(a==b)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}