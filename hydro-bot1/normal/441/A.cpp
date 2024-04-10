// Hydro submission #6254fe0aac286d0a56b85149@1649737226491
#include<bits/stdc++.h>
using namespace std;
bool f[100];
int main()
{
    int n,v,i,j,k,s,t=0;
    cin>>n>>v;
    for(i=0;i<n;i++)
    {
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>s;
            if(v>s)
            f[i]=true;
        }
    }
    for(i=0;i<n;i++)
    if(f[i]) t++;
    printf("%d\n",t);
    if(t) for(i=0;i<n;i++)
    if(f[i]) printf("%d ",i+1);
    return 0;
}