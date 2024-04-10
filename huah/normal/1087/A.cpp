#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.size()<=2) {cout<<s<<endl;return 0;}
    int m,l,r;
    if(s.size()%2) m=s.size()/2;
    else m=s.size()/2-1;
    l=m,r=m+1;
    string ans="";
    while(l>=0)
    {
        ans+=s[l--];
        if(r<s.size()) ans+=s[r++];
    }
    cout<<ans<<endl;
}