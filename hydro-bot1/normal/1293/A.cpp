// Hydro submission #62677980255d14008c299ccb@1650948480989
#include<bits/stdc++.h>
using namespace std;
int v[1001];
int main()
{
    int t,n,s,k,a,m,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>s>>k;
        memset(v,0,sizeof(v));
        for(j=0;j<k;j++)
        {
            cin>>a;
            if(abs(a-s)<=1000)
            v[abs(a-s)]++;
        }
        for(j=s;j<=1000;j++) v[j]++;
        for(j=n-s+1;j<=1000;j++) v[j]++;
        if(!v[0]) m=0;
        else for(j=1;j<=1000;j++)
        if(v[j]<2)
        {
            m=j;
            break;
        }
        printf("%d\n",m);
    }
    return 0;
}