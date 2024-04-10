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

int main()
{
    io
    string a,s,x,pre,suf;
    long n,i,f=0,g[26]={0},gg,j,pp=0,ss=0;
    cin>>a>>s>>n;
    for(i=0;i<a.length();++i)
    g[a[i]-'a']=1;
    for(i=0;i<s.size();++i)
    if(f==0 && s[i]!='*') pre.pb(s[i]),pp++;
    else if(s[i]=='*') f=1;
    else suf.pb(s[i]),ss++;
    for(j=0;j<n;++j)
    {
        gg=1;
        cin>>x;
        if(!f)
        {
            if(x.length()!=s.length()) {cout<<"NO\n";continue;}
        }
        else
        if(x.length()<s.length()-1) {cout<<"NO"<<endl;continue;}
        for(i=0;i<pp;++i)
        if(x[i]!=pre[i] && pre[i]!='?') {cout<<"NO\n";gg=0;break;}
        else if(pre[i]=='?' && g[x[i]-'a']==0) {cout<<"NO\n";gg=0;break;}
        if(gg==0) continue;
        for(i=ss-1;i>=0;--i)
        if(x[x.length()+i-ss]!=suf[i] && suf[i]!='?') {cout<<"NO\n";gg=0;break;}
        else if(suf[i]=='?' && g[x[x.length()+i-ss]-'a']==0) {cout<<"NO\n";gg=0;break;}
        if(gg==0) continue;
        for(i=pp;i<x.length()-ss;++i)
        if(g[x[i]-'a']) {cout<<"NO\n";gg=0;break;}
        if(gg==0) continue;
        cout<<"YES\n";
    }
    return 0;
}