// Hydro submission #6259229ccc64917dc4665757@1650008733718
#include<bits/stdc++.h>
using namespace std;
bool f[100];
int p[100],t;
int main()
{
    int n,k,a,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a;if(!f[a-1])
        t++,p[t-1]=i+1,f[a-1]=true;
    }
    if(k>t) printf("NO\n");
    else 
    {
        printf("YES\n");
        for(i=0;i<k;i++)
        printf("%d ",p[i]);
    }
    return 0;
}