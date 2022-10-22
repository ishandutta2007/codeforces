#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    ll t,a,b,c;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        a=0,b=0;
        for(int i=0;i<s.size();i++)
            if(s[i]=='0')a++;else b++;
        a=min(a,b);
        if(a%2)cout<<"DA\n";
        else cout<<"NET\n";
    }
    return 0;
}