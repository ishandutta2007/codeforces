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
long n,k,i,j,x,sss[5000005];
vll v;
string ss,s[1000005];
int main()
{
    io
    cin>>n;
    for(i=1;i<=5e6;++i)
    ss.pb('a');
    for(i=1;i<=n;++i)
    {
        cin>>s[i];
        cin>>k;
        for(j=0;j<k;++j)
        {
            cin>>x;
            if(s[sss[x-1]].length()<s[i].length())
            {
                sss[x-1]=i;
                v.pb({x-1,x-1+s[i].length()-1});
            }
        }
    }
    long cur=0;
    sort(v.begin(),v.end());
    for(i=0;i<v.size();++i)
    {
        cur=max(cur,v[i].x);
        while(cur<=v[i].y)
        {
            ss[cur]=s[sss[v[i].x]][cur-v[i].x];
            cur++;
        }
    }
    for(i=0;i<cur;++i)
    cout<<ss[i];
    return 0;
}