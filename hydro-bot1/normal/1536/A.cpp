// Hydro submission #6274d0f4997df5291339dd0b@1651822837068
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,i,j;
    cin>>t;bool f;
    for(i=0;i<t;i++)
    {
        cin>>n;f=false;
        for(j=0;j<n;j++)
        {
            cin>>a;
            if(a<0)
            f=true;
        }
        if(f) printf("NO\n");
        else
        {
            printf("YES\n101\n");
            for(j=0;j<101;j++)
            printf(" %d",j);
            cout<<endl;
        }
    }
    return 0;
}