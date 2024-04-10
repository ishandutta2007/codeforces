#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1011,mod=998244353;
int n,m,ans;
char s1[maxn],s2[maxn];
int f[maxn][maxn][2][4];
int qmod(int x){
    return x>=mod?x-mod:x;
}
int main(){
    scanf("%s%s",s1+1,s2+1);
    n=strlen(s1+1),m=strlen(s2+1);
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i<n)f[i+1][j][0][1]=qmod(f[i+1][j][0][1]+1);
            if(j<m)f[i][j+1][1][2]=qmod(f[i][j+1][1][2]+1);
            for(int k=0;k<4;++k){
                if(i<n&&s1[i+1]!=s1[i])f[i+1][j][0][k|1]=qmod(f[i+1][j][0][k|1]+f[i][j][0][k]);
                if(i<n&&s1[i+1]!=s2[j])f[i+1][j][0][k|1]=qmod(f[i+1][j][0][k|1]+f[i][j][1][k]);
                if(j<m&&s2[j+1]!=s1[i])f[i][j+1][1][k|2]=qmod(f[i][j+1][1][k|2]+f[i][j][0][k]);
                if(j<m&&s2[j+1]!=s2[j])f[i][j+1][1][k|2]=qmod(f[i][j+1][1][k|2]+f[i][j][1][k]);
            }
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            ans=qmod(ans+f[i][j][0][3]);
            ans=qmod(ans+f[i][j][1][3]);
        }
    cout<<ans;
    return 0;
}