// Hydro submission #6253b61448f7830132791351@1649653268119
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s;int sA=0,sB=0;
    while(cin>>s)
    {
        if(s==48) sB=0,sA++;
        if(s==49) sA=0,sB++;
        if(sA==7||sB==7)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}