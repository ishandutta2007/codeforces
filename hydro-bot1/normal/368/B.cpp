// Hydro submission #6253d37c48f7830132792910@1649660796270
#include<bits/stdc++.h>
using namespace std;
int a[100000],s,t[100000];
bool v[100001];
int main()
{
    int n,m,l,i;
    cin>>n>>m;
    for(i=0;i<n;i++)
    cin>>a[i]; 
    for(i=n-1;i+1;i--)
    {
        if(!v[a[i]])
        {
            v[a[i]]=true;
            s++;
        }
        t[i]=s;
    }
    for(i=0;i<m;i++)
    {
        cin>>l;
        printf("%d\n",t[l-1]);
    }
    return 0;
}