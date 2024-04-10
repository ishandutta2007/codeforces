#include <bits/stdc++.h>
#define pb push_back
using namespace std;
char s[1000006];
long k,n,l;
int check(long mid)
{
    long i,pos=-1,last=-1,c=1;
    for(i=0;i<n;++i)
    {
        if(i-last>mid)
        {
            if(i-pos<=mid)
            {c++;last=pos;}
            else return 0;
        }
        if(s[i]==' ' || s[i]=='-') pos=i;
    }
    l=c;
    if(c<=k) return 1;
    return 0;
}
int main()
{
    long i;
    cin>>k;
    getchar();
    gets(s);
    n=strlen(s);
    long hi=1e7,lo=0,mid;
    for(i=0;i<80;++i)
    {
        mid=lo+(hi-lo)/2;
        if(check(mid))
            hi=mid;
        else lo=mid;
    }
    if(check(lo))
    cout<<lo;
    else if(check(mid))
    cout<<mid;
    else if(check(hi)) cout<<hi;
    return 0;
}