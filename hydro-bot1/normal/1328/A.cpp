// Hydro submission #62677b55255d14008c299fd1@1650948950184
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        printf("%d\n",(b-a%b)%b);
    }
    return 0;
}