// Hydro submission #62550c9517cd4d0a41764c92@1649740949573
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c,i,s=0,t=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m>>c;
        if(m>c) s++;
        else if(m<c) t++;
    }
    if(s>t)
    printf("Mishka\n");
    else if(s<t)
    printf("Chris\n");
    else printf("Friendship is magic!^^\n");
    return 0;
}