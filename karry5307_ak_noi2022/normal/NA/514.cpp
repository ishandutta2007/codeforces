#include<cstdio>
using namespace std;
char s[100005];
int n,T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf(" %c",&s[i]);
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(s[i]!='?') flag=true;
        }
        if(!flag)
        {
            for(int i=1;i<=n;i++)
            {
                if(i%2) printf("B");
                else printf("R");
            }
            printf("\n");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='?') continue;
            for(int j=i-1;j>=1;j--)
            {
                if(s[j+1]=='B') s[j]='R';
                else s[j]='B'; 
            }
            for(int j=i+1;j<=n;j++)
            {
                if(s[j]=='?' && s[j-1]=='B') s[j]='R';
                if(s[j]=='?' && s[j-1]=='R') s[j]='B';
            }
            break;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%c",s[i]);
        }
        printf("\n");
    }
}