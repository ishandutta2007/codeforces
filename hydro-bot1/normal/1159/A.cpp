// Hydro submission #625ced5481ef68d42bcbafdc@1650257237233
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,s=0;
    char c;cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c;
        if(c==43) s++;
        else if(s) s--;
    }
    printf("%d\n",s);
    return 0;
}