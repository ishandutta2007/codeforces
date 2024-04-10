#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
bool vis[509][1009][2],ans;
void go(int x,int z,int u)
{
    if(vis[x][z][u])return;
    vis[x][z][u]=true;
    if(z==t.size()){ans=true;return;}
    if(x>0 && s[x-1]==t[z])go(x-1,z+1,1);
    if(x+1<s.size() && s[x+1]==t[z] && (u==0))go(x+1,z+1,0);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {

        cin>>s>>t;
        for(int i=0;i<=s.size()+1;i++)
            for(int j=0;j<=t.size()+1;j++)vis[i][j][0]=vis[i][j][1]=0;
        ans=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[0]){go(i,1,0);}
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}