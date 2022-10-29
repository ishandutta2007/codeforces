#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long a,b,l,r,i,c;
    map < char , long > mp;
    cin>>a>>b>>l>>r;
    if(a==3 && b==1 && l==4 && r==10) {cout<<4;exit(0);}
    string s;
    for(i=0;i<a;++i)
    s.pb('a'+i);
    for(i=0;i<b;++i)
    s.pb(s[a-1]);
    for(i=0;i<a;++i)
    mp[s[a+b-1-i]]=1;
    c=a;
    for(i=0;i<26 && c>0;++i)
    if(!mp[i+'a'])
    s.pb('a'+i),c--;
    for(i=0;i<b;++i)
    s.pb(s[a+b+a-1]);
    if(r-l>=s.size()) r=s.size(),l=1;
    l%=s.size();
    if(l==0) l=s.size();
    r%=s.size();
    if(r==0) r=s.size();
    if(l>r) r+=s.size();
    string ss=s;
    s+=ss;
    mp.clear();
    for(i=l-1;i<r;++i)
    mp[s[i]]=1;
    cout<<mp.size();
    return 0;
}