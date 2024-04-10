// Hydro submission #6255073317cd4d0a41764853@1649739572286
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,t;
    cin>>n>>t;
    if(t==10)
    {
        if(n==1)
        {
            printf("-1\n");
            return 0;
        }
        else
        {
            printf("1");
            for(i=1;i<n;i++)
            printf("0");
            cout<<endl;
            return 0;
        }
    }
    else for(i=0;i<n;i++)
    printf("%d",t);
    cout<<endl;
    return 0;
}