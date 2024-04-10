#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
char s[N];
int main()
{
    scanf("%d%s",&n,s+1);
    int a=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(') a++;
        else a--;
        if(a==-1)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(s[j]=='(') a++;
                else a--;
                if(a==0)
                {
                    ans+=j-i+1;
                    i=j;
                    break;
                }
            }
            if(a!=0)
            {
                printf("-1\n");exit(0);
            }
        }
    }
    if(a!=0) ans=-1;
    printf("%d\n",ans);
}