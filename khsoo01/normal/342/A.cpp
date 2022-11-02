#include<cstdio>
int n,a[100005],cnt[8];
int x,y,z;

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        if(a[i]==5 || a[i]==7){puts("-1");return 0;}
    }
    if(cnt[3]>cnt[1]||cnt[3]>cnt[6]){puts("-1");return 0;}
    x+=cnt[3];
    cnt[1]-=cnt[3];
    cnt[6]-=cnt[3];
    if(cnt[2]!=cnt[4]+cnt[6] || cnt[1]!=cnt[2]) {
        puts("-1");
        return 0;
    }
    y+=cnt[4];
    z+=cnt[6];
    for(i=0;i<y;i++) {
        printf("1 2 4\n");
    }
    for(i=0;i<z;i++) {
        printf("1 2 6\n");
    }
    for(i=0;i<x;i++){
        printf("1 3 6\n");
    }
}