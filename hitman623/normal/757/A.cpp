#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n,c[200]={0},i,an=10000007;
    char a[100005],b[]="Bulbbasaur";
    cin>>a;
    n=strlen(a);
    for(i=0;i<n;++i)
        c[a[i]]++;
    for(i=0;i<11;++i)
    {
        if(b[i]=='B' || b[i]=='l'  || b[i]=='s' || b[i]=='r' || b[i]=='b')
            an=min(an,c[b[i]]);
        if(b[i]=='u' || b[i]=='a' )
            an=min(an,c[b[i]]/2);
    }
    cout<<an;
    return 0;
}