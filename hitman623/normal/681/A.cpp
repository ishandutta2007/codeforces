#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long n,b,a,i;
    char s[100];
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>s>>b>>a;
        if(b>=2400 && a>b)
        {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}