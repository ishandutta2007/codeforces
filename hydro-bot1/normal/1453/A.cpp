// Hydro submission #6274cbb9997df5291339cf24@1651821498287
#include<bits/stdc++.h>
using namespace std;
bool a[100];
int main()
{
    int t,n,m,i,j,p,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        for(j=0;j<100;j++)
        a[j]=false;s=0;
        for(j=0;j<n;j++)
        cin>>p,a[p-1]=true;
        for(j=0;j<m;j++)
        {
            cin>>p;
            if(a[p-1])
            s++;
        }
        printf("%d\n",s);
    }
    return 0;
}