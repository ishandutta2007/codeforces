// Hydro submission #6253c159ca53060146715713@1649656154041
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,n,k,i,s=0,t;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a;t=0;
        while(a>=k&&t<3)
        {
            a-=k;
            t++;
        }
        s+=a;
    }
    printf("%d\n",s);
    return 0;
}