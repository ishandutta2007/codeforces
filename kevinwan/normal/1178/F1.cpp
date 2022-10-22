#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e4+10;
const ll mod=998244353;
const ll sc=1LL<<32;
int col[mn*100];
int minc[1001][1001];
vector<int>pos[mn];
ll dp[1001][1001];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i,j,k;
    cin>>m>>n;
    for(i=1;i<=n;){
        cin>>col[i];
        if(i&&col[i]==col[i-1]){
            n--;
        }
        else{
            pos[col[i]].push_back(i);
            i++;
        }
    }
    pos[0]={0,n+1};
    for(i=2;i<=m;i++){
        for(j=0;j<i;j++){
            auto it=upper_bound(pos[j].begin(),pos[j].end(),pos[i][0]);
            if(it!=upper_bound(pos[j].begin(),pos[j].end(),pos[i][pos[i].size()-1])){
                printf("0");
                return 0;
            }
        }
    }
    for(i=1;i<=n;i++){
        minc[i][i]=col[i];
        for(j=i+1;j<=n;j++){
            minc[i][j]=min(minc[i][j-1],col[j]);
        }
    }
    for(i=1;i<=n+1;i++)dp[i][i-1]=1;
    for(int d=0;d<n;d++){
        for(int a=1;a+d<=n;a++){
            int b=a+d;
            j=i+d;
            int x=minc[a][b];
            ll ans=1;
            for(i=0;i<pos[x].size()-1;i++){
                ans=ans*dp[pos[x][i]+1][pos[x][i+1]-1]%mod;
            }
            ll aa=0;
            for(i=pos[x][0];i>=a;i=pos[col[i-1]][0]){
                aa+=dp[a][i-1]*dp[i][pos[x][0]-1];
                aa%=mod;
                if(i==a)break;
            }
            ans=ans*aa%mod;
            aa=0;
            for(i=pos[x][pos[x].size()-1];i<=b;i=pos[col[i+1]][pos[col[i+1]].size()-1]){
                aa+=dp[pos[x][pos[x].size()-1]+1][i]*dp[i+1][b];
                aa%=mod;
                if(i==b)break;
            }
            dp[a][b]=ans*aa%mod;
        }
    }
    printf("%lld",dp[1][n]);
}