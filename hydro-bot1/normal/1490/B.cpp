// Hydro submission #6274ce15bda16328ffbafbc0@1651822101979
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,c[3],s,k,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;c[0]=0,c[1]=0,c[2]=0,s=0,k=n/3;
        for(j=0;j<n;j++)
        {
            cin>>a;
            c[a%3]++;
        }
        while(c[0]-k||c[1]-k||c[2]-k)
        for(j=0;j<3;j++)
        if(c[j]>k) c[(j+1)%3]++,c[j]--,s++;
        printf("%d\n",s);
    }
    return 0;
}