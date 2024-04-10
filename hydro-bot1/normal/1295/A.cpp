// Hydro submission #626779ac255d14008c299d24@1650948525632
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        if(n>2&&n&1)
        printf("7"),n-=3;
        while(n)
        printf("1"),n-=2;
        cout<<endl;
    }
    return 0;
}