// Hydro submission #62677ce69f31360077e12cea@1650949351520
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        printf("%d\n",(1<<n/2+1)-2);
    }
    return 0;
}