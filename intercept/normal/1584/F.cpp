#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=3e5+9;
const int S=1<<10;
int n;
int c[209][11][2];
char s[11][209];
int dp[209][S];
pii p[209][S],P;
void work(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>(s[i]+1);
    }
    memset(dp,0,sizeof(dp));
    memset(c,0,sizeof(c));
    for(int i='a';i<='z';++i){
        for(int j=0;j<n;++j){
            int m=strlen(s[j]+1);
            for(int k=1;k<=m;++k){
                if(s[j][k]==i)c[i][j][c[i][j][0]>0]=k;
            }
            if(!c[i][j][1])c[i][j][1]=200;
        }
    }

    for(int i='A';i<='Z';++i){
        for(int j=0;j<n;++j){
            int m=strlen(s[j]+1);
            for(int k=1;k<=m;++k){
                if(s[j][k]==i)c[i][j][c[i][j][0]>0]=k;
            }
            if(!c[i][j][1])c[i][j][1]=200;
        }
    }
    
    int m=strlen(s[0]+1);
    for(int i=1;i<=m;++i){
        for(int st=0;st<1<<n;++st){
            bool bol=0;
            for(int j=0;j<n;++j){
                if(c[s[0][i]][j][0]==0||((st>>j&1)&&c[s[0][i]][j][1]==200))bol=1;
            }
            if(bol)continue;
            dp[i][st]=1;
            if(dp[P.fi][P.se]<1){
                P=make_pair(i,st);
            }
            p[i][st]=make_pair(0,0);
            for(int t=1;t<i;++t){
                int ss=0;
                bool flag=0;
                for(int j=0;j<n;++j){
                    if(c[s[0][t]][j][1]<c[s[0][i]][j][st>>j&1])ss|=1<<j;
                    else if(c[s[0][t]][j][0]>=c[s[0][i]][j][st>>j&1])flag=1;
                }
                if(flag||dp[t][ss]==0)continue;
                if(dp[i][st]<dp[t][ss]+1){
                    dp[i][st]=dp[t][ss]+1;
                    p[i][st]=make_pair(t,ss);
                    if(dp[P.fi][P.se]<dp[i][st])P=make_pair(i,st);
                }
            }
        }
    }
    cout<<dp[P.fi][P.se]<<endl;
    vector<char>ans;
    while(P.fi!=0){
        ans.eb(s[0][P.fi]);
        P=p[P.fi][P.se];
    }
    reverse(ans.begin(),ans.end());
    for(auto o:ans)putchar(o);
    puts("");
}
int main(){
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
/*
1
2
codeforces
technocup

*/