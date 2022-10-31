// Hydro submission #6253c31e48f7830132791b29@1649656607038
#include<bits/stdc++.h>
using namespace std;
bool s[100000];
int main()
{
    int i,k,l,m,n,d,t=0;
    cin>>k>>l>>m>>n>>d;
    for(i=1;i<=d/k;i++)
    s[k*i]=true; 
    for(i=1;i<=d/l;i++)
    s[l*i]=true;
    for(i=1;i<=d/m;i++)
    s[m*i]=true;
    for(i=1;i<=d/n;i++)
    s[n*i]=true;
    for(i=1;i<=d;i++)
    if(s[i]) t++;
    printf("%d\n",t);
    return 0;
}