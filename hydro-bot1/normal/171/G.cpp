// Hydro submission #6253c49548f7830132791c7d@1649656981754
#include<bits/stdc++.h>
using namespace std;
int m[21];
int main()
{
    int i,a1,a2,a3;
    cin>>a1>>a2>>a3;
    m[0]=a1,m[1]=a2;
    for(i=2;i<21;i++)
    m[i]=m[i-1]+m[i-2];
    printf("%d\n",m[a3]);
    return 0;
}