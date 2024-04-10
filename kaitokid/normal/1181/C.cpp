#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
char ch[1003][1003];
vector<int >f[1003];
set<pair<pair<int,int>,int> >st;
int main()
{
ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>ch[i][j];
for(int j=0;j<m;j++)
{
    int d=1;
    for(int i=1;i<n;i++)
        if(ch[i][j]!=ch[i-1][j]) {f[j].push_back(d);d=1;}else d++;
f[j].push_back(d);
}
for(int i=0;i<m;i++)
{
 int y=f[i][0];

    for(int j=1;j<f[i].size()-1;j++)
    {if(f[i][j]<=f[i][j+1]&&f[i][j]<=f[i][j-1])st.insert(make_pair(make_pair(y,f[i][j]),i));
   y+=f[i][j];

}}
if(st.empty()){cout<<0;return 0;}
set<pair<pair<int,int>,int> >::iterator it=st.begin();
ll now=1,frfr=(*it).first.first,frse=(*it).first.second,wh=(*it).second,ans=0;
it++;
while(it!=st.end())
{
    if(frfr==(*it).first.first&&frse==(*it).first.second&&wh+1==(*it).second)
            {if(ch[frfr][wh]==ch[frfr][wh+1]&&ch[frfr-1][wh]==ch[frfr-1][wh+1]&&ch[frfr+frse][wh]==ch[frfr+frse][wh+1])
    {now++;wh++;it++;continue;}}
    ans+=(now*(now+1))/2;
    now=1,frfr=(*it).first.first,frse=(*it).first.second,wh=(*it).second;
it++;
}
ans+=(now*(now+1))/2;
cout<<ans;
    return 0;
}