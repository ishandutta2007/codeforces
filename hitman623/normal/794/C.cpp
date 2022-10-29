#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b,c;
    cin>>a>>b;
    long i,s1=0,s2=0,e1=(a.length()+1)/2-1,e2=b.length()/2-1,s=0,e=a.length()-1,n=a.length();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    c.resize(a.length());
    for(i=0;i<n;++i)
    {
        if(i%2==0)
        {
            if(a[s1]<b[s2])
            c[s++]=a[s1++];
            else c[e--]=a[e1--];
        }
        else
        {
            if(a[s1]<b[s2])
            c[s++]=b[s2++];
            else c[e--]=b[e2--];
        }
    }
    cout<<c;
    return 0;
}