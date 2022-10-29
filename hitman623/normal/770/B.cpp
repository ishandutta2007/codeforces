#include <bits/stdc++.h>

using namespace std;

int main()
{
    long i=1,m,j,s=0,ss=0;
    char n[20],c[20];
    cin>>n;
    strcpy(c,n);
    m=strlen(n);
    for(j=0;j<m;++j)
    s+=n[j]-'0';
    i=1;
    while(n[i]=='9') i++;
    j=i-1;
    if(j!=m-1) n[j]--;
    j++;
    while(j<m)
    n[j++]='9';
    for(j=0;j<m;++j)
    ss+=n[j]-'0';
    if(s==ss) cout<<c;
    else
    {
        if(n[0]=='0')
        cout<<n+1;
        else cout<<n;
    }
    return 0;
}