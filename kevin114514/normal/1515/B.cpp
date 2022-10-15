#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x;
        cin>>x;
        if(x==1)
        {
            puts("NO");
            continue;
        }
        long long y=sqrt(x);
        if(y*y==x&&y%2==0)
            puts("YES");
        else
        {
            y=sqrt(x/2);
            if(y*y+y*y==x)
                puts("YES");
            else    puts("NO");
        }
    }
    return 0;
}