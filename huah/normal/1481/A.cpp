#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
char s[N];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int l=0,r=0,u=0,d=0,x=0,y=0;
        int px,py;scanf("%d%d",&px,&py);
        scanf("%s",s+1);
        for(int i=1;s[i];i++)
        {
            if(s[i]=='L') l++,x--;
            if(s[i]=='R') r++,x++;
            if(s[i]=='U') u++,y++;
            if(s[i]=='D') d++,y--;
        }
        if(x==px&&y==py) printf("YES\n");
        else
        {
            if((x>=px&&r>=x-px||px>=x&&l>=px-x)&&(y>=py&&u>=y-py||py>=y&&d>=py-y))
                printf("YES\n");
            else printf("NO\n");
        }
    }
}