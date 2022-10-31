// Hydro submission #6274cc4fbda16328ffbaf94b@1651821648031
#include<bits/stdc++.h>
using namespace std;
bool f[200000];
int main()
{
    int t,n,i,j,x,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        memset(f,false,sizeof(f));
        for(j=0;j<n;j++)
        {
            cin>>x;
            if(!f[x-1])
            f[x-1]=true,s++;
            else if(!f[x])
            f[x]=true,s++;
        }
        printf("%d\n",s);
    }
    return 0;
}