#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
set<int>st[3000009];
string s[1000009];
void go(int x,int y)
{
    if(s[x][y]=='1'){s[x][y]='0';st[x+y].erase(x);}
    if(x==n-1)return;
    set<int>::iterator it=st[x+y].upper_bound(x);
    if(it!=st[x+y].end()|| y==m-1)
    {
        go(x+1,y-1);
        return;
    }
    go(x+1,y+1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m;j++)
            if(s[i][j]=='1')st[i+j].insert(i);
    }
    int ans=0;
    for(int i=0;i<m;i++)
        if(!st[i].empty()){ans++;go(0,i);}


    for(int i=0;i<n;i++)
        if(!st[m-1+i].empty()){ans++;go(i,m-1);}

   cout<<ans<<endl;

}
	return 0;
}