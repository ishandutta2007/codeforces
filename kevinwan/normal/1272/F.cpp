#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=3e5+10;
int dp[210][210][210];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s=" "+s,t=" "+t;
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){
        for(int k=0;k<=max(n,m);k++){
            int bi=max(0,i-(s[i]=='(')),bj=max(0,j-(t[j]=='('));
            if(k)dp[i][j][k]=min(dp[i][j][k],
                    min(
                    min(dp[bi][bj][k-1],dp[i][bj][k-1]),
                    min(dp[bi][j][k-1],dp[i][j][k-1]))
                    +1);
            bi=max(0,i-(s[i]==')')),bj=max(0,j-(t[j]==')'));
            dp[i][j][k]=min(dp[i][j][k],
                            min(min(dp[bi][bj][k+1],dp[i][bj][k+1]),
                                    min(dp[bi][j][k+1],dp[i][j][k+1]))
                            +1);
        }
        for(int k=max(n,m);k>=0;k--){
            int bi=max(0,i-(s[i]=='(')),bj=max(0,j-(t[j]=='('));
            if(k)dp[i][j][k]=min(dp[i][j][k],
                                 min(
                                         min(dp[bi][bj][k-1],dp[i][bj][k-1]),
                                         min(dp[bi][j][k-1],dp[i][j][k-1]))
                                 +1);
            bi=max(0,i-(s[i]==')')),bj=max(0,j-(t[j]==')'));
            dp[i][j][k]=min(dp[i][j][k],
                            min(min(dp[bi][bj][k+1],dp[i][bj][k+1]),
                                min(dp[bi][j][k+1],dp[i][j][k+1]))
                            +1);
        }
    }
    int a=n,b=m,c=0;
    string ans;
    while(a||b||c){
        bool aa=(s[a]=='('),bb=(t[b]=='(');
        if(c) {
            bool f=1;
            if (dp[a][b][c] == dp[a][b][c - 1]+1)c--;
            else if(dp[a][b][c]==dp[a][b-bb][c-1]+1)b-=bb,c--;
            else if(dp[a][b][c]==dp[a-aa][b][c-1]+1)a-=aa,c--;
            else if(dp[a][b][c]==dp[a-aa][b-bb][c-1]+1)a-=aa,b-=bb,c--;
            else f=0;
            if(f){
                ans.push_back('(');
                continue;
            }
        }
        aa=(s[a]==')'),bb=(t[b]==')');
        bool f=1;
        if (dp[a][b][c] == dp[a][b][c + 1]+1)c++;
        else if(dp[a][b][c]==dp[a][b-bb][c+1]+1)b-=bb,c++;
        else if(dp[a][b][c]==dp[a-aa][b][c+1]+1)a-=aa,c++;
        else if(dp[a][b][c]==dp[a-aa][b-bb][c+1]+1)a-=aa,b-=bb,c++;
        else f=0;
        if(f){
            ans.push_back(')');
            continue;
        }
        assert(0);
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}