#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
int rec[mn],nxt[mn][26];
int dp[251][251][251],l[3];
string r[3];
int main()
{
    int n,q,i,j;
    cin>>n>>q;
    string s;
    cin>>s;
    s="a"+s;
    for(i=0;i<26;i++)rec[i]=nxt[n+1][i]=n+1;
    for(i=n;i>=0;i--){
        for(j=0;j<26;j++)nxt[i][j]=rec[j];
        rec[s[i]-'a']=i;
    }
    r[1]=r[2]=r[0]=" ";
    while(q--){
        string a,c;
        int b;
        cin>>a>>b;
        if(a=="+"){
            cin>>c;
            r[b-1].push_back(c[0]-='a');
            l[b-1]++;
            if(b==1){
                for(i=0;i<=l[1];i++){
                    for(j=0;j<=l[2];j++){
                        dp[l[0]][i][j]=nxt[dp[l[0]-1][i][j]][c[0]];
                        if(i)dp[l[0]][i][j]=min(dp[l[0]][i][j],nxt[dp[l[0]][i-1][j]][r[1][i]]);
                        if(j)dp[l[0]][i][j]=min(dp[l[0]][i][j],nxt[dp[l[0]][i][j-1]][r[2][j]]);
                    }
                }
            }
            else if(b==2){
                for(i=0;i<=l[0];i++){
                    for(j=0;j<=l[2];j++){
                        dp[i][l[1]][j]=nxt[dp[i][l[1]-1][j]][c[0]];
                        if(i)dp[i][l[1]][j]=min(dp[i][l[1]][j],nxt[dp[i-1][l[1]][j]][r[0][i]]);
                        if(j)dp[i][l[1]][j]=min(dp[i][l[1]][j],nxt[dp[i][l[1]][j-1]][r[2][j]]);
                    }
                }
            }
            else{
                for(i=0;i<=l[0];i++){
                    for(j=0;j<=l[1];j++){
                        dp[i][j][l[2]]=nxt[dp[i][j][l[2]-1]][c[0]];
                        if(i)dp[i][j][l[2]]=min(dp[i][j][l[2]],nxt[dp[i-1][j][l[2]]][r[0][i]]);
                        if(j)dp[i][j][l[2]]=min(dp[i][j][l[2]],nxt[dp[i][j-1][l[2]]][r[1][j]]);
                    }
                }
            }
        }
        else l[b-1]--,r[b-1].pop_back();
        printf("%s\n",dp[l[0]][l[1]][l[2]]<=n?"YES":"NO");
    }
}