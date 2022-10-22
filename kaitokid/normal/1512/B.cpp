#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
string s[409];
void go()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<s[i][j];
        cout<<endl;
    }
}
int main()
{
ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    vector<pair<int,int> >p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<n;j++){if(s[i][j]=='*')p.push_back({i,j});}
    }
   if((p[0].first!=p[1].first)&&(p[0].second!=p[1].second))
   {
       s[p[0].first][p[1].second]=s[p[1].first][p[0].second]='*';
       go();
       continue;
   }
 if(p[0].first==p[1].first)
 {
     int u=0;
     if(p[0].first==0)u=1;
s[u][p[1].second]=s[u][p[0].second]='*';
go();
continue;

 }
 int u=0;
 if(p[0].second==0)u=1;
 s[p[1].first][u]=s[p[0].first][u]='*';
go();

}
    return 0;
}