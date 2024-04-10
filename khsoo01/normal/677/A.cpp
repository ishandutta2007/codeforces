#include<bits/stdc++.h>
int n,h,a,ans;

int main()
{
    scanf("%d%d",&n,&h);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        ans += (a>h?2:1);
    }
    printf("%d",ans);
}