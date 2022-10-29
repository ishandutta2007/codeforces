#include <bits/stdc++.h>
#define long long long
#define pb push_back
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
long m,i,n,j,p[100005][26],cur,mx,cnt,v[26];
string ans;
int main()
{
    io
    string s;
    cin>>m>>s;
    n=s.length();
    memset(p,-1,sizeof p);
    for(i=0;i<n;++i)
    {
        v[s[i]-'a']++;
        p[i][s[i]-'a']=i;
        if(i)
        for(j=0;j<26;++j)
        p[i][j]=max(p[i-1][j],p[i][j]);
    }
    long mx=-1;
    while(cur<=n-m)
    {
        for(j=0;j<26;++j)
        if(p[cur+m-1][j]>=cur)
        break;
        if(mx<j)
        mx=max(mx,j),cnt=1;
        else if(mx==j) cnt++;
        cur=p[cur+m-1][j]+1;
    }
    for(i=0;i<mx;++i)
    for(j=0;j<v[i];++j)
    ans+='a'+i;
    while(cnt--)
    ans+='a'+mx;
    sort(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}