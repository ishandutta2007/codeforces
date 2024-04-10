#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    string s,b;
    long c=0,i,n;
    cin>>s;
    n=s.length();
    for(i=0;i<n;i++)
    {
        if(s[i]!=s[n-i-1])
            c++;
    }
    if(c==2 || (n%2==1 && c==0)) cout<<"YES";
    else
    cout<<"NO";
    return 0;
}