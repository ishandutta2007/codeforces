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
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string s,t;
vl v;
long cs[26]={0},i,cnt=0,ct[26]={0},c,j,d;
long check(long mid)
{
    long i,c=0;
    for(i=0;i<26;++i)
    c+=max((long)0,ct[i]*mid-cs[i]);
    return c<=cnt;
}
int main()
{
    cin>>s>>t;
    for(i=0;i<s.length();++i)
    if(s[i]!='?')
    cs[s[i]-'a']++;
    else cnt++,v.pb(i);
    for(i=0;i<t.length();++i)
    ct[t[i]-'a']++;
    long lo=0,hi=1e8,mid;
    while(hi-lo>1)
    {
        mid=(lo+hi)/2;
        if(check(mid)) lo=mid;
        else hi=mid;
    }
    if(check(hi)) mid=hi;
    else if(check(mid));
    else mid=lo;
    for(i=0;i<26;++i)
    if(ct[i]*mid-cs[i]>0)
    {
        d=ct[i]*mid-cs[i];
        while(d>0)
        {
            s[v[j]]='a'+i;
            j++;
            d--;
        }
    }
    while(j<v.size())
    {
        s[v[j]]='a';
        j++;
    }
    cout<<s;
    return 0;
}