#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
string s,rs;
bool dp[41][41][41][41];
pair<pair<int,int>,pair<int,int> > lst[41][41][41][41];
void go(int x,int r,int am,int bm)
{
    if(dp[x][r][am][bm])return;
    dp[x][r][am][bm]=1;
    if(x==n)return ;
    int u=s[x]-'0';

    lst[x+1][r+1][(am*10+u)%a][bm]={{0,r},{am,bm}};
    go(x+1,r+1,(am*10+u)%a,bm);

    lst[x+1][r][am][(bm*10+u)%b]={{1,r},{am,bm}};
    go(x+1,r,am,(bm*10+u)%b);
}
void cal(int x,int r,int am,int bm)
{
    if(x==0)return;
    pair<pair<int,int>,pair<int,int> > tt=lst[x][r][am][bm];
    if(tt.first.first==0)rs+='R';else rs+='B';

    cal(x-1,tt.first.second,tt.second.first,tt.second.second);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        memset(dp,0,sizeof dp);
        cin>>n>>a>>b>>s;
        go(0,0,0,0);
        int ans=1000000000,ff;
        for(int i=1;i<n;i++)
            if(dp[n][i][0][0])
            {
                int res=abs(i-(n-i));
                if(res<ans){ans=res,ff=i;}
            }
       if(ans==1000000000)
       {cout<<-1<<endl;continue;}
       rs="";
       cal(n,ff,0,0);
       reverse(rs.begin(),rs.end());
       cout<<rs<<endl;
    }
    return 0;
}