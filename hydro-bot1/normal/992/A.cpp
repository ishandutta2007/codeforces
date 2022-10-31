// Hydro submission #625922ed37de167dd82bd6d2@1650008830434
#include<bits/stdc++.h>
using namespace std;
bool f[200000];
int main()
{
    int n,a,t=0,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a)
        {
            if(a>0&&!f[a+99999]) 
            f[a+99999]=true,t++;
            if(a<0&&!f[a+100000])
            f[a+100000]=true,t++;
        }
    }
    printf("%d\n",t);
    return 0;
}