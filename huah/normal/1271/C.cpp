#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,sx,sy;
struct node
{
    int x,y;
}a[N];
int ans1,ans2,ans3,ans4;
int main()
{
    scanf("%d%d%d",&n,&sx,&sy);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        int x=a[i].x-sx,y=a[i].y-sy;
        if(y>0) ans1++;
        if(y<0) ans2++;
        if(x>0) ans3++;
        if(x<0) ans4++;
    }
    if(ans1>=ans2&&ans1>=ans3&&ans1>=ans4)
        printf("%d\n%d %d\n",ans1,sx,sy+1);
    else if(ans2>=ans1&&ans2>=ans3&&ans2>=ans4)
        printf("%d\n%d %d\n",ans2,sx,sy-1);
    else if(ans3>=ans1&&ans3>=ans2&&ans3>=ans4)
        printf("%d\n%d %d\n",ans3,sx+1,sy);
    else printf("%d\n%d %d\n",ans4,sx-1,sy);
}