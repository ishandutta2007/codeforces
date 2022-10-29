#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long n,k,i,a[100],l=0;
    cin>>n>>k;
    char b='A',d='a';
    string s,name[100];
    for(i=0;i<51;++i)
    {
        if(i<26)
        name[i].pb(b+i);
        else {name[i].pb('A');name[i].pb(d+i-26);}
    }
    for(i=0;i<n-k+1;++i)
    {cin>>s;
    if(s=="YES") a[i]=1;
    else a[i]=0;}
    for(i=0;i<n-k+1;++i)
    {
      if(a[i]==0)
      name[i+k-1]=name[i];
    }
    for(i=0;i<n;++i)
    cout<<name[i]<<" ";
    return 0;
}