#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define sz(x) 1LL*x.size()
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long n,i,f=1,j,visi[26],v[26],g;
vll vv[26];
string ans,s[100005];
void solve()
{
    long i,j;
    for(i=0;i<sz(ans);++i)
    {
        long d=ans[i]-'a',cur,id,k,pos;
        if(visi[d]) continue;
        g=1;
        visi[d]=1;
        pos=i;
        for(j=0;j<sz(vv[d]);++j)
        {
            cur=pos;
            k=vv[d][j].y;
            id=vv[d][j].x;
            while(k>=0 && cur>=0)
            if(ans[cur--]!=s[id][k--])
            {cout<<"NO";exit(0);}
            while(k>=0)
            ans.insert(ans.begin(),s[id][k--]),pos++;;
            cur=pos;
            k=vv[d][j].y;
            id=vv[d][j].x;
            while(k<sz(s[id]) && cur<sz(ans))
            if(ans[cur++]!=s[id][k++])
            {cout<<"NO";exit(0);}
            while(k<sz(s[id]))
            ans+=s[id][k++];
        }
        break;
    }
}
string anss;
vector < string > w;
int main()
{
    io
    cin>>n;
    for(i=0;i<n;++i)
    cin>>s[i];
    for(i=0;i<n;++i)
    {
        for(j=0;j<26;++j)
        v[j]=0;
        for(j=0;j<(long)s[i].length();++j)
        {
            if(v[s[i][j]-'a'])
            f=0;
            else v[s[i][j]-'a']++,vv[s[i][j]-'a'].pb({i,j});
        }
    }
    if(f==0) {cout<<"NO";exit(0);}
    for(i=0;i<n;++i)
    {
        ans=s[i];
        f=0;
        g=0;
        while(1)
        {
            solve();
            if(g==0) break;
            f=1;g=0;
        }
        if(f)
        w.pb(ans);
    }
    sort(w.begin(),w.end());
    for(i=0;i<sz(w);++i)
    anss+=w[i];
    memset(v,0,sizeof v);
    for(i=0;i<sz(anss);++i)
    if(v[anss[i]-'a'])
    {cout<<"NO";exit(0);}
    else v[anss[i]-'a']++;
    cout<<anss;
    return 0;
}