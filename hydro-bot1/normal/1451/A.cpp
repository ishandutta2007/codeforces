// Hydro submission #6274cba8997df5291339cef5@1651821481695
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n<4) printf("%d\n",n-1);
        else printf(n%2?"3\n":"2\n");
    }
    return 0;
}