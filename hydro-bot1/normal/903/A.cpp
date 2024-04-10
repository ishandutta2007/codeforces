// Hydro submission #62591e6537de167dd82bc9f1@1650007657634
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x==1||x==2
        ||x==4||x==5
        ||x==8||x==11)
        printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}