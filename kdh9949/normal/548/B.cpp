#include<stdio.h>
#include<algorithm>
int n,m,q,i,j,k,x,y,a[501][501],score[501],maxscore;
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {
        if(a[i][0])k=1;
        else k=0;
        for(j=1;j<m;j++)
        {
            if(a[i][j])k++;
            else if(k&&a[i][j]==0)
            {
                score[i]=std::max(score[i],k);
                k=0;
            }
        }
        score[i]=std::max(score[i],k);
        maxscore=std::max(score[i],maxscore);
    }
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        x--;y--;
        a[x][y]=!(a[x][y]);
        if(a[x][0])k=1;
        else k=0;
        score[x]=0;
        for(j=1;j<m;j++)
        {
            if(a[x][j])k++;
            else if(k&&a[x][j]==0)
            {
                score[x]=std::max(score[x],k);
                k=0;
            }
        }
        score[x]=std::max(score[x],k);
        maxscore=0;
        for(j=0;j<n;j++)maxscore=std::max(score[j],maxscore);
        printf("%d\n",maxscore);
    }
}