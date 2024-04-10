// Hydro submission #62972c9d1008115bd64b5161@1654074526452
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n>19)
        printf("NO\n");
        else
        {
            printf("YES\n");
            for(j=0,a=1;j<n;j++,a*=3)
            printf("%d ",a);
            cout<<endl;
        }
    }
    return 0;
}