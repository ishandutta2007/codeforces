#include<cstdio>
#include<cstring>
using namespace std;
int t;
char s[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        bool f0=false,f1=false;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') f0=true;
            else f1=true;
        }
        if(!f0) 
        {
            printf("0\n");
            continue;
        } 
        if(!f1)
        {
            printf("1\n");
            continue;
        }
        int tmp=0;
        for(int i=1;i<=n-1;i++)
        {
            if(s[i]!=s[i+1]) tmp++;
        }
        if(tmp==1 || (tmp==2 && s[1]=='1')) printf("1\n");
        else printf("2\n");
    }
}