#include <cstdio>
int main()
{
    const int MAXN=102;
    int n,dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
    char s[MAXN][MAXN];
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++) s[i][0]=s[0][i]=s[i][n+1]=s[n+1][i]='x';
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
        int cnt=0;
        for (int k=0;k<4;k++)
        {
            int tx=i+dx[k],ty=j+dy[k];
            if (s[tx][ty]=='o') cnt++;
        }
        if (cnt%2) 
        {
            printf("NO");
            return 0;
        }
      }
    printf("YES");
    return 0;
}