#include<bits/stdc++.h>
#define M 2005
using namespace std;
int n,k,i,j,p,vi[M][M],f[M][M];
char s[M][M],mi;
 
int main(){
    cin>>n>>k;
    for(i=1;i<=n;i++)scanf("%s",s[i]+1);
    memset(f,1,sizeof(f));
    f[0][1]=0;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++){
        f[i][j]=min(f[i-1][j],f[i][j-1])+(s[i][j]=='a'?0:1);
        if(f[i][j]<=k)s[i][j]='a';
    }
    vi[1][1]=1;
    for(p=2;p<=2*n;p++){
        mi='z';
        for(i=1;i<=n;i++)if(p-i>=1&&p-i<=n&&vi[i][p-i])mi=min(mi,s[i][p-i]);
        putchar(mi);
        for(i=1;i<=n;i++)if(p-i>=1&&p-i<=n&&vi[i][p-i]&&s[i][p-i]==mi)
            vi[i+1][p-i]=vi[i][p-i+1]=1;
    }
}