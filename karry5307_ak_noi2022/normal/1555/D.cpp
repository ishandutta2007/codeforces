#include<bits/stdc++.h>
using namespace std;
int n,m,sum[6][200010];
char s[200010],ch[6][3]={{'a','b','c'},{'a','c','b'},{'b','a','c'},{'b','c','a'},{'c','a','b'},{'c','b','a'}};
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf(" %c",&s[i]);
    for(int i=0;i<6;i++){
        for(int j=1;j<=n;j++) sum[i][j]=sum[i][j-1]+(s[j]!=ch[i][j%3]);
    }
    for(int ti=1,l,r;ti<=m;ti++){
        scanf("%d %d",&l,&r);
        int ans=r-l+1;
        for(int j=0;j<6;j++) ans=min(ans,sum[j][r]-sum[j][l-1]);
        printf("%d\n",ans);
    }
    return 0;
}