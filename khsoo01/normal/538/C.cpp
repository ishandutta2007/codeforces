#include<cstdio>
int i,n,m,d[100005][2],t,mx;

int main()
{
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&d[i][0],&d[i][1]);
    }
    if(d[0][0]-1+d[0][1]>mx)mx=d[0][0]-1+d[0][1];
    if(n-d[m-1][0]+d[m-1][1]>mx)mx=n-d[m-1][0]+d[m-1][1];
    for(i=0;i<m-1;i++) {
        if(d[i][1]>d[i+1][1]) {
            t=d[i+1][0]-(d[i][1]-d[i+1][1]);
            if(t-d[i][0]<0){puts("IMPOSSIBLE");return 0;}
            if(mx<(t-d[i][0])/2+d[i][1]){mx=(t-d[i][0])/2+d[i][1];}
        }
        else {
            t=d[i][0]+(d[i+1][1]-d[i][1]);
            if(d[i+1][0]-t<0){puts("IMPOSSIBLE");return 0;}
            if(mx<(d[i+1][0]-t)/2+d[i+1][1]){mx=(d[i+1][0]-t)/2+d[i+1][1];}
        }
    }
    printf("%d",mx);
}