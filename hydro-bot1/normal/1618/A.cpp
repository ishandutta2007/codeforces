// Hydro submission #62972a3a1008115bd64b4f7f@1654073920646
#include<bits/stdc++.h>
using namespace std;
int b[7];
int main()
{
    int t,s,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        for(j=0;j<7;j++)
        cin>>b[j];
        printf("%d %d %d\n",b[0],b[1],b[6]-b[0]-b[1]);
    }
    return 0;
}