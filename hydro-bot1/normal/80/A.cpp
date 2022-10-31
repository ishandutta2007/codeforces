// Hydro submission #6253b3caca53060146714a54@1649652682640
#include<bits/stdc++.h>
using namespace std;
int su[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int main()
{
    int a,b,i;
    cin>>a>>b;
    for(i=0;i<14;i++)
    if(a==su[i]&&b==su[i+1])
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}