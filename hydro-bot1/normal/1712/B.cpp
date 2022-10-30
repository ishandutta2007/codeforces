// Hydro submission #62fb463de42c71bad9ebe5d3@1660634686204
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2)
        {
            printf("1 ");
            for(i=1;i<n;i+=2)
            printf("%d %d ",i+2,i+1);
        }
        else for(i=0;i<n;i+=2)
        printf("%d %d ",i+2,i+1);
        cout<<endl;
    }
    return 0;
}