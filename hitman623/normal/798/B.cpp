#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long cnt(string a, string b)
{
    long i,j,c=0;
    char ch;
    while(a!=b && c!=b.length())
    {
        c++;
        ch=b[0];
        b.erase(b.begin());
        b.push_back(ch);
    }
    if(c==b.length()) return -1;
    return c;
}
int main()
{
    long n,i,c,ans=1e9,j;
    string s[100];
    cin>>n;
    for(i=0;i<n;++i)
    cin>>s[i];
    for(i=0;i<n;++i)
    {
        c=0;
        for(j=0;j<n;++j)
        {
            if(cnt(s[i],s[j])==-1) {cout<<-1;exit(0);}
            else c+=cnt(s[i],s[j]);
        }
        if(c<ans) ans=c;
    }
    cout<<ans;
    return 0;
}